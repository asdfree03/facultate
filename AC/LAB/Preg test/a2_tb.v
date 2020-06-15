module a2_tb;
reg [5:0]i;
wire [3:0]o;
a2 uut(.i(i), .o(o));
integer j;
initial begin 
	for(j = 0;j<64;j = j+1) begin i = j; #1; end
end
endmodule 
