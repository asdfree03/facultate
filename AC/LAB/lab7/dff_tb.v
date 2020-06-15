module dff_tb;
reg d,clk,rst_b,set_b;
wire q;
dff dut(
	.d(d),
	.clk(clk),
	.rst_b(rst_b),
	.set_b(set_b),
	.q(q)
);
initial begin
	repeat(4) begin
	clk = 0;
	#10;
	clk = 1;
	#10;
	end
end
initial begin
	rst_b = 0;
	#5;
	rst_b = 1;
end
initial begin
d = 0;
#20;
d = 1;
#20;
d=0;
end
initial begin
set_b = 1;
#40;
set_b=0;
#5;
set_b=1;
end
endmodule
