module rgst(
	input [2:0]d, input load, clk,rst,clr,
	output reg [2:0]q
);
always @ (posedge clk, negedge rst) begin
	if(clr) q<=0;
	else if(load) q<=d;
	end
endmodule

