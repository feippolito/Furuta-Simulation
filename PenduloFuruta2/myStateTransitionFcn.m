function x = myStateTransitionFcn(x,u)

%dPhi   x(1)
%Theta  x(2)
%dTheta x(3)
%V      u


M = 0.005;
ma = 0.36233;
mp = 0.04948;
la = 230.45e-3;
lp = 239.73e-3;
g = 9.81;

J = 0.001; 
K = 0.182;
b1 = 6.0e-04;
b2 = 5.52e-04;
R = 12.38;

alpha = J + (M + 1/3*ma+mp)*la^2;

beta = (M + 1/3*mp)*lp^2;

gamma = (M + .5*mp)*la*lp;

delta = (M + .5*mp)*g*lp;

TauPhi = K*(u-K*x(3))/R;
TauTheta = -b2*x(3);

ddPhiNum = (beta*gamma*(sin(x(2))*sin(x(2))-1)*sin(x(2))*x(1)*x(1)) -...
    (2*beta*beta*cos(x(2))*sin(x(2))*x(1)*x(3)) + ( beta*gamma*sin(x(2))*x(3)*x(3))...
    - (gamma*delta*cos(x(2))*sin(x(2))) + (beta*TauPhi) - (gamma*cos(x(2))*TauTheta);

ddPhiDen = (alpha*beta)-(gamma*gamma)+((beta*beta+gamma*gamma)*sin(x(2))*sin(x(2)));

x(1) = ddPhiNum/ddPhiDen;
