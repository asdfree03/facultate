module lfsr(input clk,set,
	output [4:0]q
	);
reg [4:0]d = 5'b11111;
dff d0(
	.d(d[4]), .rst(1'd1), .clk(clk), .set(set), .q(q[0])
);
dff d1(
	.d(d[4] ^ d[0]), .rst(1'd1), .clk(clk), .set(set), .q(q[1])
);
dff d2(
	.d(d[1]), .rst(1'd1), .clk(clk), .set(set), .q(q[2])
);
dff d3(
	.d(d[2]), .rst(1'd1), .clk(clk), .set(set), .q(q[3])
);
dff d4(
	.d(d[4] ^ d[3]), .rst(1'd1), .clk(clk), .set(set), .q(q[4])
);
always @(*) begin
	d=q;
end
endmodule

