module minimization_tb(
	output reg [3:0]i,
	output [1:0]o
);
	minimization m(.i(i), .o(o));
	integer j;
	initial begin
		for(j = 0;j<13;j = j+1) #1 i = j;
end
endmodule
