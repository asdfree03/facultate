module ssgm_o_tb;
reg [31:0]i;
wire [31:0]o;
ssgm_o s(.i(i), .o(o));
initial begin
i = 32'h01234567; #1;
i = 32'h98abcdef; #1;
i = 32'h55555555; #1;
i = 32'hffffffff; #1;
i = 32'hfedcba98; #1;
i = 32'h76543210; #1;
end
endmodule
