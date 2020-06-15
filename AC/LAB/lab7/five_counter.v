module five_counter(
	input c_up,rst_b,clk,clr,[2:0]d,
	output dclk
);
wire [2:0]q;
rgst registru(  .d({(q[0] & q[1])^q[2],q[1]^q[0],~q[0]}),
		.load(c_up),
		.clr(clr | q[2]),
		.rst(rst_b),
		.clk(clk),
		.q(q)
);
assign dclk = ~(q[0] | q[1] | q[2]);
endmodule
