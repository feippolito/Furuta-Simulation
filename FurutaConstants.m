%% Furuta Constants

%FurutaSymbolic
theta2o=10*pi/180;       %Initial position theta2
x0=0;                    %Linearization around the point x0

%%
%List of parameters
global p m20 g0 l20 b10 b20 m10 L10 l10 L20 I1x0 I1y0 I1z0 I2x0 ...
    I2y0 Ixz20 I2z0 kt0 Rm0 ke0
     
% % Will change
m10 = 0.36233;
m20 = 0.04948;
L10 = 230.45e-3;
l10 = -56.69e-3;        %Maybe signal change
L20 = 239.73e-3;
l20 = 58.18e-3;
I1x0 = 0;
I1y0 = 0;
I1z0 = 3.7365e-3;
I2x0 = 0.2927e-3;
I2y0 = 0.2937e-3;
I2z0 = 0.0051e-3;
Ixz20 = -0.0131e-3; %Maybe signal chenge

b20 = 5.52e-04;

% Will not change
ke0 = 0.768;
kt0 = 0.122326;
Rm0 = 12.38;
Lm0 = 820.1e-6;
g0 = 9.81;
b10 = 6.05e-3;

% g0 = 9.8;
% b10 = 6e-4;
% b20 = 5.52e-04;
% m10 = 0.1862;
% m20 = 0.0391 + 0.0259;
% L10 = (51+44.55)*0.001;
% l10 = -34.78e-3;
% L20 = 0.2983;
% l20 = 58.47e-3;
% I1x0 = 0;
% I1y0 = 0;
% I1z0 = 3.13e-4 + 0.001;
% I2x0 = 5.34e-4;
% I2y0 = 8.41e-4;
% I2z0 = 3.1e-4;
% Ixz20 = -2.4e-4;
% kt0 = 0.182;
% Rm0 = 3.6;
% Lm0 = 1.845e-3;
% Jm0 = 0.001; 

%%Run simulink
model = 'SimulationOfFurutaL4';
load_system(model)
sim(model)

%% Linearised model

syms theta1 theta2 dtheta1 e dtheta2 m2 g l2 b1 b2 m1 L1 l1 L2 I1x I1y I1z I2x I2y Ixz2 I2z kt Rm ke
old = [theta1 theta2 dtheta1 dtheta2 e m2 g l2 b1 b2 m1 L1 l1 L2 I1x I1y I1z I2x I2y Ixz2 I2z kt Rm ke];
new = [0 x0 0 0 0 m20 g0 l20 b10 b20 m10 L10 l10 L20 I1x0 I1y0 I1z0 I2x0  I2y0 Ixz20 I2z0 kt0 Rm0 ke0];

A11 = diff(f(1),theta1);
A11 = vpa(subs(A11,old,new));

A12 = diff(f(1),theta2);
A12 = vpa(subs(A12,old,new));
A13 = diff(f(1),dtheta1);
A13 = vpa(subs(A13,old,new));

A14 = diff(f(1),dtheta2);
A14 = vpa(subs(A14,old,new));

A21 = diff(f(2),theta1);
A21 = vpa(subs(A21,old,new));

A22 = diff(f(2),theta2);
A22 = vpa(subs(A22,old,new));

A23 = diff(f(2),dtheta1);
A23 = vpa(subs(A23,old,new));

A24 = diff(f(2),dtheta2);
A24 = vpa(subs(A24,old,new));

A = double([ 0, 0, 1, 0; 0, 0, 0, 1; A11, A12, A13, A14;...
    A21, A22, A23, A24]);

B1 = diff(f(1),e);
B1 = vpa(subs(B1,old,new));

B2 = diff(f(2),e);
B2 = vpa(subs(B2,old, new));

B = double([0; 0; B1; B2]);

C1 = [ 1 0 0 0 ];
C2 = [ 0 1 0 0 ];

C=C2;
D  = 0;
%%
%Plot graphs
% figure(1)
% t=0:0.01:20;
% U = zeros(1,length(t));
% Sys1=ss(A,B,C1,D);
% Output1 = lsim(Sys1,U,t,[0 theta2o 0 0]);
% Sys2=ss(A,B,C2,D);
% Output2 = lsim(Sys2,U,t,[0 theta2o 0 0]);
% hold on
% 
% plot(t,Output1,'Color','b');
% plot(t,Output2,'Color','b');
% 
% plot(simout1,'Color','r');
% plot(simout2,'Color','r');
% 
% legend('linear','' ,'non linear','');
%% Rootlocus

% [num1,den1] = ss2tf(A,B,C1,D,1);
% G1=tf(num1,den1);
% 
% figure(2)
% h1=rlocusplot(G1);
% p1 = getoptions(h1);
% p1.Title.String = 'theta1';
% setoptions(h1,p1);
% 
% figure(3)
% [num2,den2] = ss2tf(A,B,C2,D,1);
% G2=tf(num2,den2);
% h2=rlocusplot(G2);
% p2 = getoptions(h2);
% p2.Title.String = 'theta2';
% setoptions(h2,p2);

%%
%Control
poles =  [(-4+j*4) (-4-j*4) (-2+j*2) (-2-j*2)];
K = place(A,B,poles);
sim('LinearMF');
figure(4);
plot(WStheta2,'color','b');
figure(5);
plot(WSmotor,'color','b');

poles = [(-8+j*8) (-8-j*8) (-4+j*4) (-4-j*4)];
K = place(A,B,poles);
sim('LinearMF');
figure(4);
hold on
plot(WStheta2,'color','g');
figure(5);
hold on
plot(WSmotor,'color','g');

poles = [(-4+j*4) (-4-j*4) -5 -10];
K = place(A,B,poles);
sim('LinearMF');
figure(4);
hold on
plot(WStheta2,'color','r');
title('theta2')
figure(5);
hold on
plot(WSmotor,'color','r');
title('motor')

%%
p = [g0 L10 l10 m10 I1x0 I1y0 I1z0 L20 l20 m20 I2x0 I2y0 I2z0 b10 b20 ...
    Ixz20 kt0 Rm0 Lm0 ];

F = simplify(subs(simplify(f),[g L1 l1 m1 I1x I1y I1z L2 l2 m2 I2x I2y I2z b1 b2 ...
    Ixz2 kt Rm Lm], p));

Func1 = symfun(F(1),[dtheta1,theta1,dtheta2,theta2,e,im]);
Func2 = symfun(F(2),[dtheta1,theta1,dtheta2,theta2,e,im]);
%Func3 = symfun(F(3),[dtheta1,theta1,dtheta2,theta2,e,im]);