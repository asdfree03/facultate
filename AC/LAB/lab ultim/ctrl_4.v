module ctrl_4(
	input [3:0]itr,
	input bgn,
	input clk,
	input rst_b,
	output reg fin,ld,init
);
localparam S0 = 2'b00;
localparam S1 = 2'b01;
localparam S2 = 2'b10;
reg [1:0]st,st_next;
always @(*) begin
	st_next = S0;
	case(st)
		S0: begin if(!bgn) st_next = S0;
			else if(bgn) st_next = S1;
		end
		S1: begin if(~(itr==15)) st_next = S1;
			else st_next = S2;
		end
		S2: begin st_next = S0;
		end
	endcase
end
always @(*) begin
	fin = 1'd0;
	ld = 1'd0;
	init = 1'd0;
	case (st)
		S0: if(bgn) begin ld =1'd1; init = 1'd1; end
		S1: ld = 1'd1;
		S2: fin = 1'd1;
	endcase
end
always @(posedge clk,negedge rst_b) begin
	if(!rst_b) st<=S0;
	else st<= st_next;
end	
endmodule

