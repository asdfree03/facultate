module lsfr_tb(
output reg clk,set,
output [4:0]q
);
lfsr l(.clk(clk), .set(set), .q(q));
initial begin
	set = 0; #1;
	set = 1; clk = 0;
	repeat (20) begin clk = ~clk; #1; end
end
endmodule
