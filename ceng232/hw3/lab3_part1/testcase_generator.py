from cgi import test
from operator import xor
from random import randint
def nor(p, q):
    return not (p or q)

class AB:
    def __init__(self):
        self.Q = 0
    def __call__(self, A, B):
        if A == 1 and B == 1:
            self.Q = not self.Q
        elif A == 1 and B == 0:
            self.Q = 0
        elif A == 0 and B == 1:
            self.Q = 1
        return self.Q
        
class I337:
    def __init__(self):
        self.ab1 = AB()
        self.ab2 = AB()
    def __call__(self, I0, I1, I2):
        Q0 = self.ab1(not (not I1 or I0) and (not I2), I2)
        Q1 = self.ab2(not I2, not xor(I0, not (not I1 or I2)))
        Z = xor(Q0, Q1)
        return Q0, Q1, Z

with open("testbench_ab.v", "w") as file:
    write_string = """`timescale 1ns / 1ps

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
	initial begin\n"""
    file.write(write_string)
    ab = AB()
    for testcase in range(1, 101):
            A = randint(0, 1)
            B = randint(0, 1)
            file.write(f'A={A}; B={B};\n')
            file.write("#10;\n")
            file.write('''if(2'b%d%d == {A, B}) begin
            $display("testcase #%d: correct");
            correct_testcases = correct_testcases + 1;
            end
            else $display("testcase #%d: wrong");\n''' %(A, B, testcase, testcase))
    file.write('$display("Out of %d testcases", correct_testcases, " were correct.");\n'%testcase)
    file.write("""end
    endmodule""")

with open("testbench_i337.v", "w") as file:
    write_string = """`timescale 1ns / 1ps

module testbench_ic1337;
	// Inputs
	reg I0;
	reg I1;
	reg I2;
	reg clk;
	// Outputs
	wire Q0;
	wire Q1;
	wire Z;

    // You can add additional declarations here
    // ...

	// Instantiate the Unit Under Test (UUT)
	ic1337 uut (.I0(I0),
                .I1(I1),
                .I2(I2),
                .clk(clk),
                .Q0(Q0),
                .Q1(Q1),
                .Z(Z));
					 
    // Clock Related
    // At 5, 15, 25, .. clk will change 0->1
	// At 10, 20, 30, .. clk will change 1->0
    initial clk = 0;
    always #5 clk = ~clk;
	integer testcase = 1, correct_testcases = 0;
	wire K;
	initial begin\n"""
    file.write(write_string)
    i337 = I337()
    for testcase in range(1, 101):
        I0 = randint(0, 1)
        I1 = randint(0, 1)
        I2 = randint(0, 1)
        Q0, Q1, Z = i337(I0, I1, I2)
        file.write(f'I0={I0}; I1={I1}; I2={I2};\n')
        file.write("#10;\n")
        file.write('''if(3'b%d%d%d == {Q0, Q1, Z}) begin
        $display("testcase #%d: correct");
        correct_testcases = correct_testcases + 1;
        end
        else $display("testcase #%d: wrong");\n''' %(Q0, Q1, Z, testcase, testcase))
    file.write('$display("Out of %d testcases", correct_testcases, " were correct.");\n'%testcase)
    file.write("""end
    endmodule""")
