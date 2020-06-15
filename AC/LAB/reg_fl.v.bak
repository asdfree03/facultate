module reg_fl(
	input clk, rst_b,[7:0]wr_data,[1:0]wr_addr,wr_l,[1:0]rd_addr,rd_l,
	output [7:0]rd_data
);
wire w1,w2,w3,w4;
wire [7:0]q1,q2,q3,q4;
decoder d1(
		.s(wr_addr),
		.l(wr_l),
		.o0(w1),
		.o1(w2),
		.o2(w3),
		.o3(w4)
);
rgst #(.w(8)) r1(
				.d(wr_data),
				.clk(clk),
				.rst_b(rst_b),
				.clr(0),
				.load(w1),
				.q(q1)
);
rgst #(.w(8)) r2(
				.d(wr_data),
				.clk(clk),
				.rst_b(rst_b),
				.clr(0),
				.load(w2),
				.q(q2)
);
rgst #(.w(8)) r3(
				.d(wr_data),
				.clk(clk),
				.rst_b(rst_b),
				.clr(0),
				.load(w3),
				.q(q3)
);
rgst #(.w(8)) r4(
				.d(wr_data),
				.clk(clk),
				.rst_b(rst_b),
				.clr(0),
				.load(w4),
				.q(q4)
);
mux #(.k(8)) m(
	.d0(q1),
	.d1(q2),
	.d2(q3),
	.d3(q4),
	.s(rd_addr),
	.o(rd_data)
);
endmodule
