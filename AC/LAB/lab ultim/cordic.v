module cordic(
	input bgn,
	input [15:0]theta,
	input clk,rst_b,
	output [15:0]cos,
	output fin
);
wire [15:0] w0,wrgst1,wrgst2,wrgst3,w1,w2,w3,warsh1,warsh2,watan;
wire winit,wld;
wire [3:0] wcntr;
mux m1(.d0(w1),
	.d1(1'd1),
	.s(winit),
	.o(w0)
	);
rgst rgst1(
	.d(w0),
	.ld(wld),
	.clr(0),
	.clk(clk),
	.rst_b(rst_b),
	.q(wrgst1)
	);
rgst rgst2(
	.d(w2),
	.ld(wld),
	.clr(0),
	.clk(clk),
	.rst_b(rst_b),
	.q(wrgst2)
);

rgst rgst3(
	.d(w3),
	.ld(wld),
	.clr(0),
	.clk(clk),
	.rst_b(rst_b),
	.q(wrgst3)
);
arsh arsh1(
	.a(wrgst2),
	.i(wcntr),
	.o(warsh1)
);
arsh arsh2(
	.a(wrgst1),
	.i(wcntr),
	.o(warsh2)
);
atan_const atan(
	.itr(wcntr),
	.atan(watan)
):
add_sub add1(
	.a(wrgst1),
	.b(warsh1),
	.s(!wrgst[15]),
	.q(w1)
);
add_sub add2(
	.a(wrgst2),
	.b(warsh2),
	.s(wrgst[15]),
	.q(w2)
);
add_sub add3(
	.a(wrgst3),
	.b(watan),
	.s(!wrgst[15]),
	.q(w3)
);
ctrl_4 ctrl(
	.itr(wntr),
	.bgn(bgn),
	.clk(clk),
	.rst_b(rst_b)
);
cntr cntr1(
	
);