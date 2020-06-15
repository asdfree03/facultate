module ssgm_1(
	input [31:0]i,
	output [31:0]o
);
assign o = {i[16:0],i[31:17]} ^ {i[18:0],i[31:19]} ^ {10'b0,i[31:10]};
endmodule
