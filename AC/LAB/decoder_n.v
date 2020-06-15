module decoder_n #(parameter n)(
input [n-1:0]i, en,
output reg [2**n-1:0]o
);
always @(i) begin
	if (en) begin
		o = 0;
		o[i] = 1;
	end
end
endmodule
