module reg_file_16x32(
	input [31:0]d, [3:0]s,wl, clk,rst_b,
	output [511:0]data
);
wire [15:0]w;
dec_4s dec(
	.s(s),
	.wl(wl),
	.o(w)
);
generate
	genvar i;
	for(i=0;i<16;i=i+1) begin:vect
rgst #(.w(32)) r1(
	.d(d),
	.clk(clk),
	.rst_b(rst_b),
	.clr(0),
	.load(w[i]),
	.q(data[32+32*i-1:32*i])
);
end
endgenerate
endmodule
