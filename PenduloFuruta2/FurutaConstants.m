%% Model Constants

dtSim = 0.0001;
dtDisc = 0.01;

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


% Linear model
A = zeros(4,4);
B = zeros(4,1);
C = zeros(1,4);

ko = alpha*beta - gamma^2;

%Stabilize -- UP

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

C = eye(4);

%Observability and Controlability
Ro = rank(obsv(A,C));
Rc = rank(ctrb(A,B));

%% 3x3 | Observer

A3=A(2:end,2:end);
B3=B(2:end);
C3=[0 1 0;
    0 0 1];

%% Feedback

%%Place
Kc = place(A3,B3,[-4+4i -4-4i -5]);

%%LQR
Q1=[1  0  0;
    0  100  0;
    0  0  1];

R1=10;

Kc2 = lqr(A3,B3,Q1,R1);

%%Full state observer 1 input
%L = acker(A3',C3',[-.5 -.25 -.25])';  %C3=[0 1 0]


%%Minimum order | 2 inputs  - 1 output
% Abb= A(2,2);
% Aaa=[A(3,3) A(3,4); A(4,3) A(4,4)];
% Aab = [A(3,2); A(4,2)];
% Aba = [A(2,3) A(2,4)];
% Bb = B(2);
% Ba = [B(3) B(4)]';
% 
% Ke = place(Abb,Aab',-.326 )';


%LQR/Kalman Filter | 2 inputs - 3 outputs
Qk = [0.01  0  0;
      0  100  0;
      0  0  1];
  
Rk = [1000 0;
      0 01];                    
  
% Qk = [0.01  0  0;
%       0  100  0;
%       0  0  1];
%   
% Rk = [1000 0;
%       0 01];
 
L = lqr(A3',C3',Qk,Rk)';

%% Simulation
angle = 180;
Thetao = angle*pi/180;

%% Stabilize -- DOWN

PotMax = .5*mp*lp*g;

% model = 'FurutaSimulink2';
% load_system(model)
% sim(model)