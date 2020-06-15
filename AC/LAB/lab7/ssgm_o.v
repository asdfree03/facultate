module ssgm_o(
	input [31:0]i,
	output [31:0]o
);
assign o = {i[6:0],i[31:7]}^{i[17:0],i[31:18]}^{3'b000,i[31:3]};
endmodule
