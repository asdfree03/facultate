module rgst #(parameter w=32, parameter iv={w{1'b0}}) (
	input [w-1:0]d, clk, rst_b,clr,load,
	output reg [w-1:0]q
);
always @ (posedge clk, negedge rst_b) begin
	if(rst_b) q<=iv;
	else if(clr) q<=iv;
	else if(load) q<=d;
	end
endmodule

