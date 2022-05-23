`timescale 1ns / 1ps

module ab(input A, input B, input clk, output reg Q);

 initial Q = 0;
always@(posedge clk)

case ({A, B})
	2'b11: Q = !Q;
	2'b10: Q = 0;
	2'b01: Q = 1;
endcase

endmodule

module ic1337(// Inputs
              input I0,
              input I1,
              input I2,
              input clk,
              // Outputs
              output Q0,
              output Q1,
              output Z);
				  
wire A1;
wire B2;
assign A1 = !(! I1 | I0) & !I2;
assign B2 = !(!(I2 | !I1) ^ I0);
ab ab1(A1, I2, clk, Q0);
ab ab2(!I2, B2, clk, Q1);
assign Z = Q0 ^ Q1;
endmodule
