module five_counter_tb(
output reg c_up,rst_b,clk,clr,
output dclk
);
five_counter test(
	.c_up(c_up),
	.rst_b(rst_b),
	.clk(clk),
	.clr(clr),
	.dclk(dclk)
);
integer i;
initial begin
	rst_b = 1'b1;
	#5;
	rst_b = 1'b0;
	c_up = 1'b0;
	clk = 1'b0;
	clr = 1'b0;
	for(i = 0;i<8;i=i+1) #5{clr,c_up,clk} = {clr,c_up,clk} + 1'b1;	
end
endmodule
