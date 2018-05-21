K(1)=0;
AA = A -B*K;
BB = [0;0;0;2.40343]
[x,z,t] = step(AA,BB,AA,BB);
x2 = [0 1 0 0]*x';

U=K*x';
plot(t,U);

subplot(1,2,1);
plot(t,x2);grid
title ('Theta2 versus t')
xlabel('t Sec')
ylabel('Theta2')

subplot(1,2,2);
plot(t,U);grid
title ('tensão versus t')
xlabel('t Sec')
ylabel('motor')

emax = max(abs(U))



