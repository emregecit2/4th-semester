`timescale 1ns / 1ps

module ab(input A, input B, input clk, output reg Q);

 initial Q = 0;
 
always@(posedge clk)
begin
if (A == 1 && B == 1) Q = !Q;
else if (A == 1 && B == 0) Q = 0;
else if (A == 0 && B == 1) Q = 1;
end

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
				  
reg A1;
reg B2;
always@(*)
begin
A1 <= !(! I1 || I0) && !I2;
B2 <= !(!(I2 || !I1) ^^ I0);
end
ab ab1(A1, I2, clk, Q0);
ab ab2(!I2, B2, clk, Q1);
assign Z = Q0 ^^ Q1;
endmodule
