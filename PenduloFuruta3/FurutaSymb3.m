dtSim = 0.0001;
dtDisc = 0.01;

mr = 0.36233;
mp = 0.04948;

Lr = 230.45e-3;
Lp = 239.73e-3;
g = 9.81;

Jr = 0.05; 
Jp = 0.01; 

Dr = 6.0e-03;
Dp = 5.52e-03;

Rm = 12.38;
km = 0.01;




Jt = Jp*mp*Lr*Lr+Jr*Jp + 0.25 *Jr*mp*Lp*Lp;

g = 9.81;

% syms Alpha Theta dAlpha dTheta ddTheta ddAlpha Vm Tau
%  Eq0 = Tau == km*(Vm - km*dTheta)/Rm;
%  Eq1 = ddTheta == (1/Jt)*(-(Jp + 0.25*mp*Lp*Lp)*Dr*dTheta + 0.5*mp*Lp*Lr*Dp*dAlpha + 0.25 *mp*mp*Lp*Lp*g*Alpha + (Jp+0.25*mp*Lp*Lp)*Tau);
%  Eq2 = ddAlpha == (1/Jt)*(0.5*mp*Lp*Lr*Dr*dTheta - (Jr + mp*Lr*Lr)*Dp*dAlpha - 0.5*mp*Lp*g*(Jr+mp*Lr*Lr)*Alpha - 0.5 *mp*Lp*Lr*Tau);

 X0=pi;
 [A,B,C,D] = linmod('sys',[0 0 X0 0]', 0 )
 
A=A(2:end,2:end);
B=B(2:end);
C=[0 1 0;
   0 0 1];

 K=place(A,B,[[-0.2+0.2i -0.2-0.2i -0.2]]);
 
 
 Thetao=185*pi/180