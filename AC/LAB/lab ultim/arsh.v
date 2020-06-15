module arsh(
	input [15:0]a, input [3:0]i,
	output [15:0]o
);
	assign o = $signed(a)>>i;
endmodule
