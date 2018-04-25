%% Furuta Constants

%List of parameters
global p m20 g0 l20 b10 b20 m10 L10 l10 L20 I1x0 I1y0 I1z0 I2x0 ...
    I2y0 Ixz20 I2z0 kt0 Rm0 ke0
     
% % Will change
m10 = 0.36233;
m20 = 0.04948;
L10 = 230.45e-3;
l10 = -56.69e-3; %Maybe signal change
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

k10=(I2y0 + I1z0 + L10^2*m20+l10^2*m10+l20^2*m20)/2;
k20=(I2x0+l20^2*m20)/2;


%% Linearised model

syms theta1 theta2 dtheta1 e dtheta2 m2 g l2 b1 b2 m1 L1 l1 L2 I1x I1y I1z I2x I2y Ixz2 I2z kt Rm ke
old = [theta1 theta2 dtheta1 dtheta2 e m2 g l2 b1 b2 m1 L1 l1 L2 I1x I1y I1z I2x I2y Ixz2 I2z kt Rm ke];
new = [0 pi 0 0 0 m20 g0 l20 b10 b20 m10 L10 l10 L20 I1x0 I1y0 I1z0 I2x0  I2y0 Ixz20 I2z0 kt0 Rm0 ke0];

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

%%

p = [g0 L10 l10 m10 I1x0 I1y0 I1z0 L20 l20 m20 I2x0 I2y0 I2z0 b10 b20 ...
    Ixz20 kt0 Rm0 Lm0 ];

F = simplify(subs(simplify(f),[g L1 l1 m1 I1x I1y I1z L2 l2 m2 I2x I2y I2z b1 b2 ...
    Ixz2 kt Rm Lm], p));

Func1 = symfun(F(1),[dtheta1,theta1,dtheta2,theta2,e,im]);
Func2 = symfun(F(2),[dtheta1,theta1,dtheta2,theta2,e,im]);
%Func3 = symfun(F(3),[dtheta1,theta1,dtheta2,theta2,e,im]);

