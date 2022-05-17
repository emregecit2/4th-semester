`timescale 1ns / 1ps 
module lab3_2(
			input[4:0] smartCode,
			input CLK, 
			input lab, //0:Digital, 1:Mera
			input [1:0] mode, //00:exit, 01:enter, 1x: idle 
			output reg [5:0] numOfStuInMera,
			output reg [5:0] numOfStuInDigital,
			output reg restrictionWarnMera,//1:show warning, 0:do not show warning
			output reg isFullMera, //1:full, 0:not full
			output reg isEmptyMera, //1: empty, 0:not empty
			output reg unlockMera,	//1:door is open, 0:closed
			output reg restrictionWarnDigital,//1:show warning, 0:do not show warning
			output reg isFullDigital, //1:full, 0:not full
			output reg isEmptyDigital, //1: empty, 0:not empty
			output reg unlockDigital //1:door is open, 0:closed
	);
	 
	// You may declare your variables below	
	
	initial begin
			numOfStuInMera=0;
			numOfStuInDigital=0;
			restrictionWarnMera=0;
			isFullMera=0;
			isEmptyMera=1'b1;
			unlockMera=0;		
			restrictionWarnDigital=0;
			isFullDigital=0;
			isEmptyDigital=1'b1;
			unlockDigital=0;
	end
	
	always @(posedge CLK)
	begin
		unlockDigital = 0;
		unlockMera = 0;
		restrictionWarnDigital = 0;
		restrictionWarnMera = 0;
		isEmptyDigital = numOfStuInDigital == 0;
		isFullDigital = numOfStuInDigital == 30;
		isEmptyMera = numOfStuInMera == 0;
		isFullMera = numOfStuInMera == 30;
		case (lab)
			0: begin
				case (mode)
					2'b01: begin
						if (!isFullDigital) begin
							if (numOfStuInDigital < 15) begin
								unlockDigital = 1;
								numOfStuInDigital = numOfStuInDigital + 1;
							end
							else begin
								if (^smartCode) begin // isOdd
									unlockDigital = 1;
									numOfStuInDigital = numOfStuInDigital + 1;
								end
								else restrictionWarnDigital = 1;
							end
						end
					end

					2'b00: begin
						unlockDigital = 1;
						numOfStuInDigital = numOfStuInDigital - 1;
					end

				endcase
			end

			1: begin
				case (mode)
					2'b01: begin
						if (!isFullMera) begin
							if (numOfStuInMera < 15) begin
								unlockDigital = 1;
								numOfStuInMera = numOfStuInMera + 1;
							end
							else begin
								if (^smartCode) restrictionWarnMera = 1;
								else begin
									unlockMera = 1;
									numOfStuInMera = numOfStuInMera + 1;
								end
							end
						end
					end

					2'b00: begin
						unlockMera = 1;
						numOfStuInMera = numOfStuInMera - 1;
					end
				endcase
			end
		endcase
	end
	
endmodule

