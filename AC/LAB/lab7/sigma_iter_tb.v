module sigma_iter_tb;
reg [511:0]blk;
reg ld_rgs;
reg upd_rgs;
wire [31:0]w0;
sigma_iter asd(.blk(blk), .ld_rgs(ld_rgs), .upd_rgs(upd_rgs), .w0(w0));
always begin
ld_rgs = 1;
upd_rgs = 1;
blk = 0;
#2;
repeat(10) begin #2 blk= blk+1;
	#1 upd_rgs = ~upd_rgs;
	#1 ld_rgs = ~ld_rgs;
end
end
endmodule
