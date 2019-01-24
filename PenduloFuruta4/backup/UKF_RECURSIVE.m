%ym_valores = zeros(2,N);
x_UFK = zeros(2,N);

for k=2:N-1
    sP = chol(P,'lower');
    chi_p = [x(:,k-1), x(:,k-1)*ones(1,L)+sqrt(L+lambda)*sP, x(:,k-1)*ones(1,L)-sqrt(L+lambda)*sP];
    chi_m = zeros(2,2*L);

    for i=1:(2*L+1)
        chi_m(:,i) = stateTransition(chi_p(:,i),u(:,k));
    end

    x_m = chi_m*wm;
    P_m = Q;
    for i = 1:2*L+1
     P_m = P_m + wc(i)*(chi_m(:,i) - x_m)*(chi_m(:,i) - x_m)';
    end

    psi_m = zeros(2,2*L);
    for i=1:(2*L+1)
        psi_m(:,i) = chi_p(:,i);
    end

    y_m = psi_m*wm;
   % ym_valores = y_m(:,k);

    Pyy = R;
    Pxy = zeros(L,1);
    for i = 1:2*L+1
     Pyy = Pyy + wc(i)*(psi_m(:,i) - y_m)*(psi_m(:,i) - y_m)';
     Pxy = Pxy + wc(i)*(chi_m(:,i) - x_m)*(psi_m(:,i) - y_m)';
    end

    K = Pxy*pinv(Pyy);                    % Calculate Kalman gt=0:5000;
    x_UKF(:,k) = x_m + K*(yt(:,k) - y_m); % Update state estimate
    P = P_m - K*Pyy*K';                   % Update covariance estimate
   
end

simulinkoutput = output';
simulinkreal = real';
t=0:Ts:(N-1)*Ts;
subplot(2,1,1)
plot(t,x_UKF(1,:),t,simulinkoutput(1,:),t,simulinkreal(1,:));
legend({'UKF Matlab','UKF Simulink','Real'})

subplot(2,1,2)
plot(t,x_UKF(2,:),t,simulinkoutput(2,:),t,simulinkreal(2,:));
legend({'UKF Matlab','UKF Simulink','Real'})