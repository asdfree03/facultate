module rgst #(
	parameter w = 16	//register's width
)(
	input clk, 
	input rst_b,	//asynchronous reset; active low
	input [w-1:0] d, 
	input ld, 
	input clr,	//synchronous reset; active high
	output reg [w-1:0] q
);

	always @ (posedge clk, negedge rst_b)
		if (!rst_b)
			q <= 1'd0;
		else if (clr)
			q <= 1'd0;
		else if (ld)
			q <= d;
endmodule
