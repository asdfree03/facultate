module decoder_n_tb;
parameter n= 2;
reg [n-1:0]i; reg en;
wire [2**n-1:0]o;
decoder_n #(.n(n)) uut(.i(i),.en(en), .o(o));
	initial begin 
		i = 0; en=1; 
		repeat (2**n-1) begin
			#1 i=i+1; 
		end #1;
	end
endmodule
