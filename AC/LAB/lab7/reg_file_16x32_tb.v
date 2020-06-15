module reg_file_16x32_tb;
reg [31:0]d; 
reg [3:0]s;
reg wl,clk,rst_b;
wire [511:0]data;
reg_file_16x32 regf(.d(d),.s(s),.wl(wl),.clk(clk),.rst_b(rst_b),.data(data));
initial begin
	wl=1;
	rst_b = 0;
	#1 s = 0;
	repeat(16) begin
	clk = 1;
		#1 clk= ~clk;
		#1 d = 0;
		repeat(33000) #1 d = d+1;
		#1 clk= ~clk;
		#1 d = 0;
		repeat(33000) #1 d = d+1;
		#1 s=s+1;
		end
	end
endmodule
