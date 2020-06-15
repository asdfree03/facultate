module lsfr_tb(
output reg clk,rst_b,
output [3:0]q
);
lfsr_4 dut(
	.clk(clk),
	.rst_b(rst_b),
	.q(q)
);
initial begin
clk = 1;
rst_b=1;
	repeat(16) #1 clk = ~clk;
	
end
endmodule
