module ex2(
	input [5:0]i,
	output reg[3:0]o
);
integer s;
always @(*) begin
	s = i[5] + i[4] + i[3] + i[2] + i[1] +i[0];
	if(s == 2) o = i[3:0];
	else if(s==3) o = i[5:2];
	else if(s==4) o = {i[5:4],i[2],i[0]};
	else if(s==5) o = {i[5],i[3],i[1:0]};
	else if(s==6) o = {i[5:4],i[1:0]};
	else o = i[4:1];
end
endmodule
