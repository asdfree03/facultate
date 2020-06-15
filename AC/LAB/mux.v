module mux(
	input [15:0]d0,d1,
	input s,
	output reg [15:0]o
);
always @(*) begin
		if(s==1) o=d1;
		else if(s==0) o =d0;
end
endmodule
