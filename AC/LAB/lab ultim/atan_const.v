module atan_const (input [3:0] itr, output reg [15:0] atan);
  always @ (*)
    case (itr)
      4'd0:   atan = 16'h3244;
      4'd1:   atan = 16'h1dac;
      4'd2:   atan = 16'h0fae;
      4'd3:   atan = 16'h07f5;
      4'd4:   atan = 16'h03ff;
      4'd5:   atan = 16'h0200;
      4'd6:   atan = 16'h0100;
      4'd7:   atan = 16'h0080;
      4'd8:   atan = 16'h0040;
      4'd9:   atan = 16'h0020;
      4'd10:  atan = 16'h0010;
      4'd11:  atan = 16'h0008;
      4'd12:  atan = 16'h0004;
      4'd13:  atan = 16'h0002;
      4'd14:  atan = 16'h0001;
      default:atan = 16'h0000;
    endcase
endmodule
