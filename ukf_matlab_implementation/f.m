function x2 = f(x,u)

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
Ts = 0.001;

xdPhi = x(1);
xdTheta = x(2);
Voltage = u(1);
xTheta = u(2);

D = zeros(2);
C = zeros(2);
G = zeros(2,1);
Tau = zeros(2,1);

D(1,1)= alpha+beta*sin(xTheta)*sin(xTheta);
D(2,1) = gamma*cos(xTheta);
D(1,2) = D(2,1);
D(2,2) = beta;

C(1,1) = beta*sin(xTheta)*cos(xTheta)*xdTheta;
C(2,1) = -beta*cos(xTheta)*sin(xTheta)*xdPhi;
C(1,2) = (beta*cos(xTheta)*sin(xTheta)*xdPhi)-(gamma*sin(xTheta)*xdTheta);
C(2,2) = 0;

G(1) = 0;
G(2) = -gamma*sin(xTheta);

Tau(1) = Voltage - ((ke*ke)/Re)*xdPhi - (xdPhi * kb);
Tau(2) = -kb*xdTheta;

x2 = pinv(D)*(Tau-C*x-G).*Ts + x;

end