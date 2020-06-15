module div6_cntr(
	input clk,clr,c_up,
	output reg dclk
);
reg [2:0]d = 3'b0;
wire [2:0]q;
rgst r(.clk(clk), .ld(c_up), .clr(clr || (d[2] && d[0])), .d({(d[0] && d[1]) || d[2],d[1] ^ d[0],~d[0]}), .q(q));
always @(*) begin
	dclk = ~(q[0] || q[1] ||q[2]) ;
end
always @(*) begin
	d = q;
end
endmodule
