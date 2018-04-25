clc;
close all;
%define symbolic variables
syms theta1 dtheta1 theta2 dtheta2 ddtheta1 ddtheta2 tau1 real
syms vc1 vc2 w1 w2 real
syms g m1 m2 I1x I1y I1z I2x I2y I2z Ixz2 l1 L1 l2 L2 b1 b2 e real
syms T P real
%Define Position of the center of mass
pC1 = l1*[cos(theta1) sin(theta1) 0]';
pA = L1*[cos(theta1) sin(theta1) 0]';
pC2 = pA + l2*[sin(theta2)*sin(theta1) -sin(theta2)*cos(theta1) ...
cos(theta2)]';
pT = pA + L2*[sin(theta2)*sin(theta1) -sin(theta2)*cos(theta1) ...
cos(theta2)]';
%Angular velocities in 1st body-fixed frame
w1 = [0 0 dtheta1]';
w2 = [dtheta2 0 dtheta1]';
%Angular velocities in 1st body-fixed frame
vc1 = [0 dtheta1*l1 0]';
vA = [0 dtheta1*L1 0]';
%vc2 = vA + w2 x rAc2
vc2 = [l2*dtheta1*sin(theta2) dtheta1*L1-l2*dtheta2*cos(theta2) ...
-l2*dtheta2*sin(theta2)]';

%Inertia Matrices
I1 = diag([I1x I1y I1z]);
I2 = [[I2x 0 Ixz2];...
 [0 I2y 0 ];...
 [Ixz2 0 I2z];];
%Rotating the I2 Inertia matrix:
R = [1 0 0;...
 0 cos(theta2) -sin(theta2);...
 0 sin(theta2) cos(theta2);];
I2r = simplify(R'*I2*R);
%Kinetic Energy
Tp = m2*(vc2')*vc2/2 + w2'*I2r*w2/2;
T = m1*(vc1')*vc1/2 + w1'*I1*w1/2 + m2*(vc2')*vc2/2 + w2'*I2r*w2/2;
T = simplify(T);
%Potential Energy
P = m2*g*l2*cos(theta2);
%Total pendulum Energy
Ep = simplify(Tp + P);
%Total Energy dT/dt is for the swing up control, needed later
TE = simplify(T + P);
dTE = diff(TE,dtheta1)*ddtheta1 + diff(TE,theta1)*dtheta1...
 + diff(TE,dtheta2)*ddtheta2 + diff(TE,theta2)*dtheta2;
%The Lagrangian
Lg = simplify(T - P);
%Partial derivative in dtheta1 and dtheta2
partial_dtheta1 = simplify(diff(Lg,dtheta1));
partial_dtheta2 = simplify(diff(Lg,dtheta2));
%Time derivative
time_der1 = diff(partial_dtheta1,dtheta1)*ddtheta1 +...
diff(partial_dtheta1,theta1)*dtheta1...
 + diff(partial_dtheta1,dtheta2)*ddtheta2 +...
diff(partial_dtheta1,theta2)*dtheta2;
time_der1 = simplify(time_der1);
time_der2 = diff(partial_dtheta2,dtheta1)*ddtheta1 +...
diff(partial_dtheta2,theta1)*dtheta1...
 + diff(partial_dtheta2,dtheta2)*ddtheta2 +...
diff(partial_dtheta2,theta2)*dtheta2;
time_der2 = simplify(time_der2);
%Partial derivative in theta1 and theta2
partial_theta1 = simplify(diff(Lg,theta1));
partial_theta2 = simplify(diff(Lg,theta2));
%Equations of motion
Eq1 = simplify(time_der1 - partial_theta1);
Eq2 = simplify(time_der2 - partial_theta2);
%Matrix Form: H*ddq + C + G = Tau
%Matrix terms for Eq1
H11 = diff(Eq1,ddtheta1);
H12 = diff(Eq1,ddtheta2);
G1 = diff(Eq1,g)*g;
C1 = Eq1 - H11*ddtheta1 - H12*ddtheta2 - G1;
%Matrix terms for Eq2
H21 = diff(Eq2,ddtheta1);
H22 = diff(Eq2,ddtheta2);
G2 = diff(Eq2,g)*g;
C2 = simplify(Eq2 - H21*ddtheta1 - H22*ddtheta2 - G2);
syms kt Rm Lm Jm im dim
% D matrix combines mechanical inertia with electrical inductance
D_mtx = [H11 H12 0;...
 H21 H22 0; 0 0 Lm];
C_vec = [C1-(kt*im); C2; (kt*dtheta1 + Rm*im)];
G_vec = [G1; G2; 0;];
B_mtx = diag([b1 b2 0]);
% ---------------------------------------------------------------------
f = simplify(D_mtx\(-C_vec - G_vec + [0 0 e]' - B_mtx*[dtheta1;
dtheta2; im;]));