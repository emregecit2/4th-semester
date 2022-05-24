`timescale 1ns / 1ps

module lab4ROM (input [3:0] romAddr, output reg[4:0] romOutput);
	always@(romAddr) 
		case (romAddr)
			0 : assign romOutput = 5'b00000;
			1 : assign romOutput = 5'b00001;
			2 : assign romOutput = 5'b00110;
			3 : assign romOutput = 5'b00111;
			4 : assign romOutput = 5'b01011;
			5 : assign romOutput = 5'b01100;
			6 : assign romOutput = 5'b01101;
			7 : assign romOutput = 5'b01110;
			8 : assign romOutput = 5'b11101;
			9 : assign romOutput = 5'b11110;
			10 : assign romOutput = 5'b11111;
			11 : assign romOutput = 5'b10000;
			12 : assign romOutput = 5'b10111;
			13 : assign romOutput = 5'b11000;
			14 : assign romOutput = 5'b11001;
			15 : assign romOutput = 5'b11010;
		endcase

endmodule
																							
module lab4RAM (
	input ramMode, //0:read, 1:write
	input [3:0] ramAddr, 
	input [4:0] ramInput,
	input  ramOp, //0:polynomial, 1:derivative
	input [1:0] ramArg,  //00:+1, 01:+2, 10:-1, 11:-2
	input CLK, 
	output reg [8:0] ramOutput);

	integer i;
	integer argVal;
	integer ramVal;
	reg [8:0]ramData[16:0];
	initial begin
		for (i=0; i<=15; i=i+1) begin
			ramData[i] = 9'b000000000;
		end
	end
	always@(ramArg) case (ramArg)
		2'b00 : argVal = 1;
		2'b01 : argVal = 2;
		2'b10 : argVal = -1;
		2'b11 : argVal = -2;
	endcase
	always@(posedge CLK) begin
		if (ramMode == 1)
			ramVal = 0;
			case (ramOp)
				0 : begin
					for (i=0; i<=4; i=i+1) begin
						ramVal = ramVal + (ramInput[i]?-1:1) * argVal**i;
					end
				end
				1 : begin
					for (i=0; i<=3; i=i+1) begin
						ramVal = ramVal + (ramInput[i + 1]?-1:1) * (i + 1) * argVal**i;
					end
				end
			endcase
			if (ramVal >= 0)
				ramData[ramAddr] = ramVal;
			else begin
				ramData[ramAddr] = -ramVal;
				ramData[ramAddr][8] = 1;
			end
	end
	always@(ramMode) if (ramMode==0) ramOutput = ramData[ramAddr];
endmodule


module polMEM(input mode, input [3:0] memAddr, input op, input [1:0] arg, input CLK, output wire [8:0] memOutput);

	/*Don't edit this module*/
	wire [4:0] romOutput;

	lab4ROM RO(memAddr, romOutput);
	lab4RAM RA(mode, memAddr, romOutput, op, arg, CLK, memOutput);



endmodule
