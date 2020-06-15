module dff(
	input d,rst,clk,set,
	output reg q
);
	always @(posedge clk, posedge rst) begin
		if(set) q<=d;
	end
endmodule

