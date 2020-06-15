module rgst(
	input clk,ld,clr, [2:0]d,
	output reg [2:0]q
);
always @(posedge clk) begin
	if(ld) begin
	if(clr) q<=0;
	else q<=d;
	end
end
endmodule
