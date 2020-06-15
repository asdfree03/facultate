module add_sub(
	input [15:0]a,[15:0]b,
	input s,
	output [15:0]q
);
	assign q = s ? a-b : a+b;
endmodule
