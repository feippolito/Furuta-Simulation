g = 9.81;

kb = 6e-4;
m1 = 0.1862;
m2 = 0.0391 + 0.0259;
L1 = (51+44.55)*0.001;
L2 = 0.2983;
M = 0;
J = 0.001;

ke = 0.182;
Re = 3.6;



alpha = J + (M+m1/3+m2)*L1^2;
beta = (M + m2/3)*L2^2;
gamma = (M + m2/2)*L2*L1;
sigma = (M + m2/2)*g*L2;

%% Simulation parameters

initial_state =pi+0.05;
Ts = 0.001;
dtDisc = 0.01;
Reference = [0 0 0 0];

StepX = 10;
distrub = 12;
disturb = distrub*pi/180;

%% Linearization

% A matrix
A = zeros(4,4);
A(1,2) = 1;
A(2,3) = -(sigma*gamma)/(alpha*beta-gamma^2);
A(3,4) = 1;
A(4,3) = (alpha*sigma)/(alpha*beta-gamma^2);

% B matrix
B = zeros(4,2);
B(2,1) = beta/(alpha*beta-gamma^2);
B(2,2) = -gamma/(alpha*beta-gamma^2);
B(4,1) = -gamma/(alpha*beta-gamma^2);
B(4,2) = alpha/(alpha*beta-gamma^2);

% C matrix
C = [0 0 1 1];

%% Pseudo Linear System

% Pseudo A matrix
Ap = zeros(4,4);

Ap(1,2) = 1;

Ap(2,1) = 0;      Ap(2,2) = -B(2,1)*(ke^2/Re + kb); 
Ap(2,3) = A(2,3); Ap(2,4) = -B(2,2)*kb;

Ap(3,4) = 1;

Ap(4,1) = 0;      Ap(4,2) = -B(4,1)*(ke^2/Re + kb); 
Ap(4,3) = A(4,3); Ap(4,4) = -B(4,2)*kb;

% Pseudo B matrix

Bp = zeros(4,1);

Bp(2) = B(2,1)*ke/Re;  
Bp(4) = B(4,1)*ke/Re;   

% Controlability and Observability
Control = rank(ctrb(Ap,Bp));
Observ = rank(obsv(Ap,C));

% State Feedback Control
%K = place(Ap,Bp,[-5 -3 -2+2j -2-2j]);
K = place(Ap,Bp,[-7 -5 -4+4j -4-4j]);
%K = place(Ap,Bp,[-10 -8 -6+6j -6-6j]);
