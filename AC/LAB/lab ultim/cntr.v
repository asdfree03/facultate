module cntr(
	input c_up,rst_b,clk,clr,
	output [3:0]q
);
	reg [3:0] counter_up;

always @(posedge clk, negedge rst_b)
begin
if(!rst_b)
 counter_up <= 4'd0;
else
 counter_up <= counter_up + 4'd1;
end 
assign counter = counter_up;
endmodule

