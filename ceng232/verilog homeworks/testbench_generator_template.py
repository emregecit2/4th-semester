from random import randint
from uut import UUT

with open("./testbench.v", "w") as file:
    write_string = """`timescale 1ns / 1ps

module testbench;
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
	initial begin\n"""
    file.write(write_string)
    uut = UUT()
    for testcase in range(1, 101):
            # Generate random inputs
            A = randint(0, 1)
            B = randint(0, 1)
            file.write(f'A={A}; B={B};\n')
            file.write("#10;\n")
            file.write('''if(2'b%d%d == {A, B}) begin
            $display("testcase #%d: correct");
            correct_testcases = correct_testcases + 10;
            end
            else $display("testcase #%d: wrong");\n''' %(A, B, testcase, testcase))
    file.write('$display("Out of %d testcases", correct_testcases, " were correct.");\n'%testcase)
    file.write("""end
    endmodule""")
