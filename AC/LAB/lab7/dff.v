module dff(
	input d,clk,rst_b,set_b,
	output reg q
);
always @(posedge clk,negedge rst_b) begin
	if(!rst_b) q<=0;
	else if(!set_b) q<=1;
	else q<=d;
end
endmodule
