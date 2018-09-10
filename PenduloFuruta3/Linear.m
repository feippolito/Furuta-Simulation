M = 0;
ma = 0.36233;
mp = 0.04948;
la = 230.45e-3;
lp = 239.73e-3;
g = 9.81;

J = 0.1; 
K = 0.01;
b1 = 0.1;
b2 = 5.52e-04;
R = 12.38;

alpha = J + (M + 1/3*ma+mp)*la^2;
beta = (M + 1/3*mp)*lp^2;
gamma = (M + .5*mp)*la*lp;
delta = (M + .5*mp)*g*lp;

Thetao = 0;
[A,B,C,D] = linmod('sys',[0 0 Thetao 0]', 0 )