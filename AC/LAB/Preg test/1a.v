module a2(
	input [5:0]i,
	output reg [3:0]o
);
always @(*) begin
	if(i<10) o = i;
	else if(i>9 && i<20) o = 1;
	else if(i>19 && i<30) o = 2;
	else if(i>29 && i<40) o = 3;
	else if(i>39 && i<50) o = 4;
	else if(i>49 && i<60) o = 5;
	else o = 6;
end
endmodule
