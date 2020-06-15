module lfsr_4(
	input i,clk, rst_b,
	output [3:0]q
);
dff d0(
	.d(q[3] ^ i),	
	.clk(clk),
	.rst_b(rst_b),
	.set_b(1'd1),
	.q(q[0])
);
dff d1(
	.d(q[0]^q[3]),	
	.clk(clk),
	.rst_b(rst_b),
	.set_b(1'd1),
	.q(q[1])
);
dff d2(
	.d(q[1]),	
	.clk(clk),
	.rst_b(rst_b),
	.set_b(1'd1),
	.q(q[2])
);
dff d3(
	.d(q[2]),	
	.clk(clk),
	.rst_b(rst_b),
	.set_b(1'd1),
	.q(q[3])
);
endmodule
