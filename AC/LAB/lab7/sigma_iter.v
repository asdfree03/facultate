module sigma_iter(
	input [511:0]blk,
	input ld_rgs,
	input upd_rgs,
	output [31:0]w0
);
wire [511:0]a,b;
wire [31:0]c,d;
wire [31:0]s;
mux m[15:0](    .d0(blk),
		.d1({b[479:0],s}),
		.s(ld_rgs),
		.o(a)
);
rgst r[15:0](
	.d(a),
	.load(upd_rgs),
	.q(b)
);
ssgm_o s0(.i(b[479:448]),
	  .o(c)
);
ssgm_1 s1(.i(b[63:32]),
	  .o(d)
);
assign s = b[511:480] + c+d+b[223:192];
assign w0 = b[511:480];
endmodule
