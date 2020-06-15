module fsm_3s_tb;
reg a,b,clk,rst_b;
wire m,n,p;
fsm_3s uut(.a(a), .b(b), .clk(clk), .rst_b(rst_b), .m(m), .n(n) ,.p(p));
initial begin
	clk = 1;
	repeat (10) #1 clk = ~clk;
end
initial begin
	rst_b = 0;
	a=0;
	repeat (2) begin
		b = 0; #1;
		repeat(1) begin 
			b= b+1; #1;
		end
		a= a+1;
	end
end
endmodule
