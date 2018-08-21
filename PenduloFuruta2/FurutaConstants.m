%% Model Constants

dtSim = 0.0001;
% dtSim=1e-2;
dtDisc = 0.005;

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

% Stabilize -- Down


% Observability and Controlability

Ro = rank(obsv(A,C));
Rc = rank(ctrb(A,B));

%Feedback

Kc = place(A,B,[-4+4i -4-4i -4 -5]);

% Q=[10   0  0    0;
%    0    1  0    0;
%    0    0  100  0;
%    0    0  0  10];
% 
% R=10;
% 
% Kc2 = lqr(A,B,Q,R);
%% 3x3

A3=A(2:end,2:end);
B3=B(2:end);
% C3=C(2:end);
C3=[0 1 0; 0 0 1];

%%LQE
% Ro = rank(obsv(A3,C3));
% Rc = rank(ctrb(A3,B3));
% 
% Vd=[0.1    0     0;
%     0      0.1   0;
%     0      0     0.1];
% 
% Vn=0.001;
% 
% [L,P,E]=lqe(A3,Vd,C3,Vd,Vn);

% L=acker(A3',C3',[-2 -2 -2])';


%%Full state
A3=A(2:end,2:end);
B3=B(2:end);
C3=[ 0 1 0];
L = acker(A3',C3',[-.5 -.25 -.25])';

%%Minimum order
% Abb= [A(2,2) A(2,4);
%      A(4,2) A(4,4)];
% 
% Aaa=A(3,3);
% 
% Aab = [A(3,2) A(3,4)];
% 
% Aba = [A(2,3) A(4,3)]';
% 
% Bb = [B(2) B(4)]';
% Ba = B(3);
% 
% Ke = place(Abb,Aab',[-2 -3]);
%%

% Simulation
angle = 170;
Thetao = angle*pi/180;

% Stabilize -- DOWN
PotMax = .5*mp*lp*g;

% model = 'FurutaSimulink2';
% load_system(model)
% sim(model)