module div6_cntr_tb;
reg clk, clr, c_up;
wire dclk;
div6_cntr div(.clk(clk), .clr(clr), .c_up(c_up), .dclk(dclk));
initial begin
	clk = 0;
	repeat (20) #1 clk = ~clk;
end
initial begin
	clr = 1;
	c_up = 1;
	#1;
	clr = 0;
end
endmodule
