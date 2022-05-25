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
    reg[4:0] cache_size, cache_index, i, count, v;
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
    always @(posedge clk) begin
        case (mode)
            0: begin
                case (opCode)
                    3'b011: begin
                        invalidOp = 1;
                    end
                    3'b111: begin 
                        invalidOp = 1;
                    end
                    default: begin
                        instruction_cache[cache_size] = opCode;
                        value_cache[cache_size] = value;
                        cache_size = cache_size + 1;
                        invalidOp = 0;
                    end
                endcase
            end
            1: begin
                current_result = result;
                case (instruction_cache[cache_index])
                    3'b000: begin // ADD
                        result = result + value_cache[cache_index];
                    end
                    3'b001: begin // ADD2
                        result = result + previous_result + value_cache[cache_index];
                    end
                    3'b010: begin // FMA
                        result = result * previous_result + value_cache[cache_index];
                    end
                    3'b100: begin // POPC
                        count = 0;
                        i = 0;
                        for (i = 0; i <= 9; i = i + 1) begin
                            count = count + result[i];
                        end
                        result = count;
                    end
                    3'b101: begin // BREV
                        result = ~result;
                    end
                    3'b110: begin // SETR
                        v = value_cache[cache_index];
                    end
                endcase
                cache_index = cache_index + 1;
                if (cache_index == cache_size) begin
                    cache_index = v;
                end
                previous_result = current_result;
            end
        endcase
        previous_result = result;
    end
endmodule
