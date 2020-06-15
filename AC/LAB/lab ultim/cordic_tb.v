module cordic_tb (output reg clk, rst_b, bgn, [15:0] theta, output fin, [15:0] cos);
  cordic test (.clk(clk), .rst_b(rst_b), .bgn(bgn), .theta(theta), .fin(fin), .cos(cos));
  initial begin clk = 1'd0; repeat (500) #50 clk = ~clk; end
  initial begin rst_b = 1'd0; #5 rst_b = 1'd1; end
  initial begin bgn = 1'd1; #100 bgn = 1'd0; #1700 bgn = 1'd1; #100 bgn = 1'd0; #1700 bgn = 1'd1; #100 bgn = 1'd0; end
  initial begin theta =  16'h2183; #1800 theta =  16'h3244; #1800 theta =  16'h4305; end
endmodule
