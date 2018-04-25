%% Motor simulation of Inverted-Pendulum

clc;
close all;
%Define global variables
global ssA ssB
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
vc1 = [0 -dtheta1*l1 0]'; %Talvez tenha um menos antes
vA = [0 dtheta1*L1 0]';

%vc2 = vA + w2 x rAc2
vc2 = [l2*dtheta1*sin(theta2) dtheta1*L1-l2*dtheta2*cos(theta2) ... 
-l2*dtheta2*sin(theta2)]';

%Inertia Matrices
I1 = diag([I1x I1y I1z]);
I2 = [[I2x 0 Ixz2]; [0 I2y 0 ]; [Ixz2 0 I2z]];

%Rotating the I2 Inertia matrix:
R = [1 0 0; 0 cos(theta2) -sin(theta2); 0 sin(theta2) cos(theta2);];
I2r = simplify(R'*I2*R);

%Kinetic Energy
Tp = m2*(vc2')*vc2/2 + w2'*I2r*w2/2;
T = m1*(vc1')*vc1/2 + w1'*I1*w1/2 + m2*(vc2')*vc2/2 + w2'*I2r*w2/2;
T = simplify(T)

%Potential Energy
P = m2*g*l2*cos(theta2)

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
time_der1 = diff(partial_dtheta1,dtheta1)*ddtheta1 + ...
diff(partial_dtheta1,theta1)*dtheta1...
 + diff(partial_dtheta1,dtheta2)*ddtheta2 + ...
diff(partial_dtheta1,theta2)*dtheta2;
time_der1 = simplify(time_der1);
time_der2 = diff(partial_dtheta2,dtheta1)*ddtheta1 + ...
diff(partial_dtheta2,theta1)*dtheta1 ...
 + diff(partial_dtheta2,dtheta2)*ddtheta2 + ...
diff(partial_dtheta2,theta2)*dtheta2;
time_der2 = simplify(time_der2);

%Partial derivative in theta1 and theta2
partial_theta1 = simplify(diff(Lg,theta1))
partial_theta2 = simplify(diff(Lg,theta2))

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
syms kt Rm Lm Jm im dim ke

% D matrix combines mechanical inertia with electrical inductance
%D_mtx = [H11 H12 0; H21 H22 0; 0 0 Rm];
%C_vec = [ C1-kt*(e-ke*dtheta1)/Rm ; C2; (kt*dtheta1);]; %Substituir segundo kt por ke
%G_vec = [G1; G2; 0;];
%B_mtx = diag([b1 b2 0]);

D_mtx = [H11 H12 ; H21 H22 ];
C_vec = [ C1-kt*(e-ke*dtheta1)/Rm ; C2]; %Substituir segundo kt por ke
G_vec = [G1; G2];
B_mtx = diag([b1 b2]);

f = simplify(D_mtx\(-C_vec - G_vec - B_mtx*[dtheta1;...
    dtheta2]));
% ---------------------------------------------------------------------
% Create MATLAB functions for each EOM entry
param_list = {'g','p(1)'; 'L1','p(2)'; 'l1','p(3)'; 'm1','p(4)'; ...
 'I1x','p(5)';'I1y','p(6)';'I1z','p(7)';...
 'L2','p(8)';'l2','p(9)'; 'm2','p(10)';...
'I2x','p(11)';'I2y','p(12)';'I2z','p(13)';'b1','p(14)';...
'b2','p(15)';'Ixz2','p(16)';...
'kt','p(17)';'Rm','p(18)';'Lm','p(19)';'Jm','p(20)';};

list_q = {'theta1','q(1)'; 'theta2','q(2)';'im','q(3)'};
list_dq = {'dtheta1','q(1)'; 'dtheta2','q(2)'; 'dim','q(3)'};
write_fcn('D_matrix.m',{'q','p'},[list_q; param_list],{D_mtx,'D'});
write_fcn('C_vector.m',{'q','dq','p'},[list_q; list_dq;...
param_list],{C_vec,'C'});
write_fcn('G_vector.m',{'q','p'},[list_q; param_list],{G_vec,'G'});
write_fcn('KinEnergy.m',{'q','dq','p'},[list_q; list_dq;...
param_list],{T,'KE'});
write_fcn('PotEnergy.m',{'q','p'},[list_q; param_list],{P,'PE'});
write_fcn('PendEnergy.m',{'q','dq','p'},[list_q; list_dq;...
param_list],{Ep,'Pend_E'});
write_fcn('CG1.m',{'q','p'},[list_q; param_list],{pC1,'pC1'});
write_fcn('CG2.m',{'q','p'},[list_q; param_list],{pC2,'pC2'});
write_fcn('pAxis.m',{'q','p'},[list_q; param_list],{pA,'pA'});
write_fcn('pTip.m',{'q','p'},[list_q; param_list],{pT,'pT'});

% ------------------------------------------------------------------------
%Linearization about initial position
% q = [theta1 theta2 dtheta1 dtheta2];
%f = simplify(D_mtx\(-C_vec - G_vec + [0 0 e]' - B_mtx*[dtheta1;...
%dtheta2; im;]));

subs_vec = [theta1 theta2 dtheta1 dtheta2 im];
lin_point = [0 0 0 0 0];
A11 = simplify(subs(diff(f(1),theta1),subs_vec,lin_point));
A12 = simplify(subs(diff(f(1),theta2),subs_vec,lin_point));
A13 = simplify(subs(diff(f(1),dtheta1),subs_vec,lin_point));
A14 = simplify(subs(diff(f(1),dtheta2),subs_vec,lin_point));
A15 = simplify(subs(diff(f(1),im),subs_vec,lin_point));
A21 = simplify(subs(diff(f(2),theta1),subs_vec,lin_point));
A22 = simplify(subs(diff(f(2),theta2),subs_vec,lin_point));
A23 = simplify(subs(diff(f(2),dtheta1),subs_vec,lin_point));
A24 = simplify(subs(diff(f(2),dtheta2),subs_vec,lin_point));
A25 = simplify(subs(diff(f(2),im),subs_vec,lin_point));
A31 = simplify(subs(diff(f(3),theta1),subs_vec,lin_point));
A32 = simplify(subs(diff(f(3),theta2),subs_vec,lin_point));
A33 = simplify(subs(diff(f(3),dtheta1),subs_vec,lin_point));
A34 = simplify(subs(diff(f(3),dtheta2),subs_vec,lin_point));
A35 = simplify(subs(diff(f(3),im),subs_vec,lin_point));
B1 = subs(diff(f(1),e),subs_vec,lin_point);
B2 = subs(diff(f(2),e),subs_vec,lin_point);
B3 = subs(diff(f(3),e),subs_vec,lin_point);
%State Space including motor: x = [theta1 theta dtheta1 dtheta2 i]
ssA = [[0 0 1 0 0];
 [0 0 0 1 0];
 [A11 A12 A13 A14 A15];
 [A21 A22 A23 A24 A25];
 [A31 A32 A33 A34 A35];];
ssB = [0; 0; B1; B2; B3;];