%% Model Constants
M = 0;
ma = 0.36233;
mp = 0.04948;
la = 230.45e-3;
lp = 239.73e-3;
g = 9.81;

J = 0.1; 
Km = 0.01;
b1 = 0.1;
b2 = 5.52e-04;
R = 12.38;

alpha = J + (M + 1/3*ma+mp)*la^2;

beta = (M + 1/3*mp)*lp^2;

gamma = (M + .5*mp)*la*lp;

delta = (M + .5*mp)*g*lp;


%%Equations
syms Phi dPhi Theta dTheta V;

x0 = pi; %Linearisation around the point x0;

old = [Phi dPhi  Theta dTheta  V];
new = [0     0    x0      0    0];
TauPhi = Km*(V-Km*dTheta)/R;

TauTheta = b2*dTheta;

numddPhi = (beta*gamma*(sin(Theta)*sin(Theta)-1)*cos(Theta)*sin(Theta)*dPhi*dPhi)...
    - (2*beta*beta*cos(Theta)*sin(Theta)*dPhi*dTheta) + ( beta*gamma*sin(Theta)*dTheta*dTheta)...
    - (gamma*delta*cos(Theta)*sin(Theta)) + (beta*TauPhi) - (gamma*cos(Theta)*TauTheta);

denddPhi =(alpha*beta)-(gamma*gamma)+((beta*beta+gamma*gamma)*sin(Theta)*sin(Theta));

ddPhi = numddPhi/denddPhi;

numddTheta=(beta*(alpha + beta*sin(Theta)*sin(Theta))*cos(Theta)*sin(Theta)*dPhi*dPhi)+...
    (2*beta*gamma*(1-sin(Theta)*sin(Theta))*sin(Theta)*dPhi*dTheta)-...
    ( gamma*gamma*cos(Theta)*sin(Theta)*dTheta*dTheta)+( delta*(alpha+beta*sin(Theta)*sin(Theta))...
    *sin(Theta))-(gamma*cos(Theta)*TauPhi)+((alpha+beta*sin(Theta)*sin(Theta))*TauTheta);

denddTheta=(alpha*beta)-(gamma*gamma)+((beta*beta+gamma*gamma)*sin(Theta)*sin(Theta));

ddTheta = numddTheta/denddTheta;

%% Linear model

A21 = diff(ddPhi,Phi);
A21 = vpa(subs(A21,old,new));

A22 = diff(ddPhi,dPhi);
A22 = vpa(subs(A22,old,new));

A23 = diff(ddPhi,Theta);
A23 = vpa(subs(A23,old,new));

A24 = diff(ddPhi,dTheta);
A24 = vpa(subs(A24,old,new));

A41 = diff(ddTheta,Phi);
A41 = vpa(subs(A41,old,new));

A42 = diff(ddTheta,dPhi);
A42 = vpa(subs(A42,old,new));

A43 = diff(ddTheta,Theta);
A43 = vpa(subs(A43,old,new));

A44 = diff(ddTheta,dTheta);
A44 = vpa(subs(A44,old,new));

A = double([ 0 1 0 0 ; A21 A22 A23 A24 ; 0 0 0 1; A41 A42 A43 A44]);

B2 = diff(ddPhi,V);
B2 = vpa(subs(B2,old,new));

B4 = diff(ddTheta,V);
B4 = vpa(subs(B4,old,new));

B = double([0 ;B2 ;0 ;B4]);

C = [0 0 1 0];

D = 0;

p = [(-2+j*2) (-2-j*2) -4 -1];
K = place(A,B,p);
