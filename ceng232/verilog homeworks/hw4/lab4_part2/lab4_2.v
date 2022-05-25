`timescale 1ns / 1ps

module lab4_2(// INPUTS
              input wire      mode,
              input wire[2:0] opCode,
              input wire[3:0] value,
              input clk,
              input reset,
              // OUTPUTS
              output reg[9:0] result,
              output reg cacheFull,
              output reg invalidOp,
              output reg overflow);

    //================//
    // INITIAL BLOCK  //
    //================//
    //Modify the lines below to implement your design
    reg[9:0] previous_result;
    reg[9:0] current_result;
    reg[2:0]instruction_cache[0:31];
    reg[4:0]value_cache[0:31];
    reg[4:0] cache_size, cache_index, i, count, v, temp;
    initial begin
        cache_size = 0;
        cache_index = 0;
        result = 0;
        previous_result = 0;
        v = 0;
    end

    //================//
    //      LOGIC     //
    //================//
    //Modify the lines below to implement your design
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            cache_size = 0;
            cache_index = 0;
            previous_result = 0;
            result = 0;
            invalidOp = 0;
            overflow = 0;
            cacheFull = 0;
        end
        else begin
            invalidOp = 0;
            case (mode)
                0: begin
                    case (opCode)
                        3'b011: invalidOp = 1;
                        3'b111: invalidOp = 1;
                        default: begin
                            if (!cacheFull) begin
                                instruction_cache[cache_size] = opCode;
                                value_cache[cache_size] = value;
                                cache_size = cache_size + 1;
                            end
                        end
                    endcase
                end
                1: begin
                    current_result = result;
                    case (instruction_cache[cache_index])
                        3'b000: begin 
                            temp = result + value_cache[cache_index];
                            if (temp > 2**10 - 1) overflow = 1;
                            else overflow = 0;
                            result = temp;
                        end
                        3'b001: begin
                            temp = result + previous_result + value_cache[cache_index];
                            if (temp > 2**10 - 1) overflow = 1;
                            else overflow = 0;
                            result = temp;
                        end
                        3'b010: begin
                            temp = result * previous_result + value_cache[cache_index];
                            if (temp > 2**10 - 1) overflow = 1;
                            else overflow = 0;
                            result = temp;
                        end
                        3'b100: begin // POPC
                            count = 0;
                            i = 0;
                            for (i = 0; i <= 9; i = i + 1) count = count + result[i];
                            result = count;
                            overflow = 0;
                        end
                        3'b101: begin
                            result = ~result;
                            overflow = 0;
                        end
                        3'b110: begin
                            v = value_cache[cache_index];
                            overflow = 0;
                        end
                    endcase
                    cache_index = cache_index + 1;
                    if (cache_index == cache_size) cache_index = v;
                    previous_result = current_result;
                end
            endcase
            cacheFull = cache_size == 32;
        end
    end
endmodule
