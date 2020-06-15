module dec_4s(
	input [3:0]s,wl,
	output reg [15:0]o
);
always @(s) begin
if(wl) begin
	o=0;
	o[s] = 1;
end
end
endmodule
