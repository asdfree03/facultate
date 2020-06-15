module comparator_tb(
	output reg [1:0]x, [1:0]y,
	output eq,le,gt
);

comparator c(.x(x), .y(y), .eq(eq), .le(le), .gt(gt));
integer i,j;
initial begin
	for(i = 0;i<4;i= i+1) begin
		#1;
		x = i;
		for(j = 0;j<4;j=j+1) begin #1; y = j; end
	end
end
endmodule
