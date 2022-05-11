`timescale 1ns / 1ps

module testbench_ab;
    // Inputs
	reg A;
	reg B;
	reg clk;
	// Outputs
	wire Q;

	// Instantiate the Unit Under Test (UUT)
	ab uut (
		.A(A),
		.B(B),
		.clk(clk),
		.Q(Q)
	);

	// At 5, 15, 25, .. clk will change 0->1
	// At 10, 20, 30, .. clk will change 1->0
    initial clk = 0;
	always #5 clk = ~clk;
    integer testcase = 1, correct_testcases = 0;
	initial begin
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #1: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #1: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #2: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #2: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #3: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #3: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #4: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #4: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #5: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #5: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #6: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #6: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #7: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #7: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #8: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #8: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #9: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #9: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #10: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #10: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #11: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #11: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #12: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #12: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #13: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #13: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #14: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #14: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #15: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #15: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #16: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #16: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #17: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #17: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #18: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #18: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #19: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #19: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #20: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #20: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #21: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #21: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #22: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #22: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #23: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #23: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #24: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #24: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #25: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #25: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #26: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #26: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #27: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #27: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #28: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #28: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #29: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #29: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #30: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #30: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #31: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #31: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #32: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #32: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #33: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #33: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #34: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #34: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #35: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #35: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #36: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #36: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #37: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #37: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #38: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #38: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #39: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #39: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #40: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #40: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #41: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #41: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #42: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #42: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #43: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #43: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #44: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #44: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #45: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #45: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #46: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #46: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #47: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #47: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #48: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #48: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #49: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #49: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #50: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #50: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #51: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #51: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #52: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #52: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #53: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #53: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #54: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #54: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #55: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #55: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #56: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #56: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #57: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #57: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #58: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #58: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #59: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #59: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #60: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #60: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #61: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #61: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #62: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #62: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #63: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #63: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #64: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #64: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #65: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #65: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #66: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #66: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #67: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #67: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #68: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #68: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #69: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #69: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #70: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #70: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #71: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #71: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #72: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #72: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #73: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #73: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #74: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #74: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #75: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #75: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #76: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #76: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #77: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #77: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #78: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #78: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #79: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #79: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #80: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #80: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #81: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #81: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #82: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #82: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #83: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #83: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #84: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #84: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #85: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #85: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #86: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #86: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #87: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #87: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #88: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #88: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #89: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #89: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #90: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #90: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #91: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #91: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #92: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #92: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #93: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #93: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #94: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #94: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #95: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #95: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #96: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #96: wrong");
A=1; B=0;
#10;
if(2'b10 == {A, B}) begin
            $display("testcase #97: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #97: wrong");
A=0; B=1;
#10;
if(2'b01 == {A, B}) begin
            $display("testcase #98: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #98: wrong");
A=1; B=1;
#10;
if(2'b11 == {A, B}) begin
            $display("testcase #99: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #99: wrong");
A=0; B=0;
#10;
if(2'b00 == {A, B}) begin
            $display("testcase #100: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #100: wrong");
$display("Out of 100 testcases", correct_testcases, " were correct.");
end
    endmodule