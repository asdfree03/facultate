module fsm_3s(
	input a,b,clk,rst_b,
	output reg m,n,p
);
localparam s0=2'b00;
localparam s1=2'b01;
localparam s2=2'b10;
reg [1:0] st,st_next;
always @ (*) begin
	st_next = s0;
	case(st)
		s0: begin 
			if(!a) st_next = s0;
			else if(!b) st_next = s1;
			else st_next = s2;
		end
		s1:begin
			st_next = s1;
		end
		s2:begin
			if(a) st_next = s0;
			else st_next = s2;
		end
	endcase
	
end
always @ (*) begin
	m = 1'd0;
	n= 1'd1;
	p = 1'd0;
	case (st)
		s0: begin
			if(!a) m = 1'd1;
			else begin
				if(!b) n = 1'd0;
				else p = 1'd1;
			end
		end
		s1: begin
			p =1'd1;
			m=1'd1;
		end
		s2:begin
			n = 1'd0;
			if(!a) m = 1'd1;
		end
	endcase
end
always @ (posedge clk,negedge rst_b)  begin
	if(!rst_b) st<= s0;
	else st<=st_next;
end
endmodule
