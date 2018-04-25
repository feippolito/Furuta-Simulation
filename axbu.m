function [A B] = axbu(f1,f2)

syms theta1 theta2 dtheta1 e dtheta2 m2 g l2 b1 b2 m1 L1 l1 L2 I1x I1y I1z I2x I2y Ixz2 I2z kt Rm ke
global m20 g0 l20 b10 b20 m10 L10 l10 L20 I1x0 I1y0 I1z0 I2x0 ...
    I2y0 Ixz20 I2z0 kt0 Rm0 ke0
old = [theta1 theta2 dtheta1 dtheta2 e m2 g l2 b1 b2 m1 L1 l1 L2 I1x I1y I1z I2x I2y Ixz2 I2z kt Rm ke];
new = [0 0 0 0 0 m20 g0 l20 b10 b20 m10 L10 l10 L20 I1x0 I1y0 I1z0 I2x0  I2y0 Ixz20 I2z0 kt0 Rm0 ke0];

A11 = diff(f1,theta1);
A11 = vpa(subs(A11,old,new));

A12 = diff(f1,theta2);
A12 = vpa(subs(A12,old,new));

A13 = diff(f1,dtheta1);
A13 = vpa(subs(A13,old,new));

A14 = diff(f1,dtheta2);
A14 = vpa(subs(A14,old,new));

A21 = diff(f1,theta1);
A21 = vpa(subs(A21,old,new));

A22 = diff(f1,theta2);
A22 = vpa(subs(A22,old,new));

A23 = diff(f1,dtheta1);
A23 = vpa(subs(A23,old,new));

A24 = diff(f1,dtheta2);
A24 = vpa(subs(A24,old,new));

A = [ 0, 0, 1, 0; 0, 0, 0, 1; A11, A12, A13, A14; A21, A22, A23, A24];


B1 = diff(f1,e);
B1 = vpa(subs(B1,old,new));

B2 = diff(f2,e);
B2 = vpa(subs(B2,old, new));

B = [0; 0; B1; B2];