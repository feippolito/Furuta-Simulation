%% Model Constants
dtSim = 0.0001;
dtDisc = 0.05;

M = 0;
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

%% Select Controller
Sel = 3;

%1 - Control Up
%2 - Control Down
%3 - Swing Up

%% Linear model
A = zeros(4,4);
B = zeros(4,1);
C = zeros(1,4);

ko = alpha*beta - gamma^2;

% Stabilize -- UP

A(1,2) = 1;
A(2,2) = (-K^2*beta)/(R*ko);
A(2,3) = (-delta*gamma)/(R*ko);
A(2,4) = (b2*gamma)/(ko);
A(3,4) = 1;
A(4,2) = (gamma*K^2)/(ko*R);
A(4,3) = (alpha*delta)/(ko);
A(4,4) = (-b2*alpha)/(ko);

B(2) = (beta*K)/(ko*R);
B(4) = (-gamma*K)/(ko*R);

C(3) = 1;

% Observability and Controlability

Ro = rank(obsv(A,C));
Rc = rank(ctrb(A,B));

Kc = place(A,B,[-2+2i -2-2i -1 -4]);

% Simulation

angle = 15;
Thetao = angle*pi/180;

% Stabilize -- DOWN

PotMax = .5*mp*lp*g;
