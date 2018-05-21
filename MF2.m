x0=[0; 0; 0; 0];
K(1)=0;
Ak= A-B*K;
sysMF=ss(Ak,B,C,D);
T=0:0.01:10;
U = K*
lsim(sysMF,U,T,x0)

