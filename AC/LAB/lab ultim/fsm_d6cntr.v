module fsm_d6cntr(
	input clk,
	input rst_b,	//asynch
	input clr,
	input c_up,
	output dclk
);

	reg [5:0] din;
	wire [5:0] din_nxt;

	assign din_nxt[1] = (din[0] & c_up & (~clr)) | (din[1] & (~c_up) & (~clr));
	//TO COMPLETE...

	assign dclk = din[0] | //TO COMPLETE;

	always @ (posedge clk, negedge rst_b)
		if (! rst_b) din<=6'd1;
		else din <= din_nxt;	
endmodule
