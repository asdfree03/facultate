module decoder(
input [1:0]i, l,
output reg o0,o1,o2,o3
);
always @(i) begin
if(l) begin
		if(i==0) o0= 1;
		if(i==1) o1= 1;
		if(i==2) o2 = 1;
		if(i==3) o3= 1;
end
end
endmodule
