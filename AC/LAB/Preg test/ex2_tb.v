module ex2_tb;
reg [5:0]i;
wire [3:0]o;
ex2 e(.i(i), .o(o));
integer j;
initial begin
	for(j=0;j<64;j = j+1) #1 i = j;
end
endmodule
