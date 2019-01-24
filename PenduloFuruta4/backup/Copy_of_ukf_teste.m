%% Before filter execution
% System properties
T = Ts; % Sampling time
N = size(input,1); % Number of time steps for filter

% Step 1: Define UT Scaling parameters and weight vectors
L = 2; % Size of state vector
alphaC = 1; % Primary scaling parameter
betaC = 2; % Secondary scaling parameter (Gaussian assumption)
kappa = 0; % Tertiary scaling parameter
lambda = alphaC^2*(L+kappa) - L;
wm = ones(2*L + 1,1)*1/(2*(L+lambda));
wc = wm;
wm(1) = lambda/(lambda+L);
wc(1) = lambda/(lambda+L) + 1 - alphaC^2 + betaC;

% Step 2: Define noise assumptions
Q = eye(L)*2e-8;
R = 2e-8;

% Step 3: Initialize state and covariance
x = zeros(L, N); % Initialize size of state estimate for all k
x(:,1) = [0; 0]; % Set initial state estimate
P0 = eye(2)*0.001; % Set initial error covariance
% Simulation Only: Calculate true state trajectory for comparison
% Also calculate measurement vector
xt = input'; % Initialize size of true state for all k
yt = measurement';
chi_m = zeros(L,2*L+1);
psi_m = zeros(2,2*L+1);

%% Execute Unscented Kalman Filter
P = P0; % Set first value of P to the initial P0
for k = 2:N
 % Step 1: Generate the sigma-points
 sP = chol(P,'lower'); % Calculate square root of error covariance
 % chi_p = "chi previous" = chi(k-1)
 chi_p = [x(:,k-1), x(:,k-1)*ones(1,L)+sqrt(L+lambda)*sP, ...
 x(:,k-1)*ones(1,L)-sqrt(L+lambda)*sP];

 % Step 2: Prediction Transformation
 % Propagate each sigma-point through prediction
 % chi_m = "chi minus" = chi(k|k-1)
 for i=1:(2*L+1)
    chi_m(:,i) = stateTransition(chi_p(:,i),xt(:,k));
 end
 x_m = chi_m*wm; % Calculate mean of predicted state
 % Calculate covariance of predicted state
 P_m = Q;
 for i = 1:2*L+1
    P_m = P_m + wc(i)*(chi_m(:,i) - x_m)*(chi_m(:,i) - x_m)';
 end

 % Step 3: Observation Transformation
 % Propagate each sigma-point through observation
 
for i=1:(2*L+1)
    psi_m(:,i) = [0 chi_m(2,i)];
end
 y_m = psi_m*wm; % Calculate mean of predicted output
 % Calculate covariance of predicted output
 % and cross-covariance between state and output
 Pyy = R;
 Pxy = zeros(L,2);
 
 for i = 1:2*L+1
     Pyy = Pyy + wc(i)*(psi_m(:,i) - y_m)*(psi_m(:,i) - y_m)';
     Pxy = Pxy + wc(i)*(chi_m(:,i) - x_m)*(psi_m(:,i) - y_m)';
 end

 % Step 4: Measurement Update
 K_UKF = Pxy/Pyy; % Calculate Kalman gain
 x(:,k) = x_m + K_UKF(1,:)*(yt(:,k) - y_m); % Update state estimate
 P = P_m - K_UKF*Pyy*K_UKF'; % Update covariance estimate
 
end

simulinkoutput = output';
simulinkreal = real';

t=0:Ts:(N-1)*Ts;
subplot(2,1,1)
plot(t,x(1,:),t,simulinkoutput(1,:),t,simulinkreal(1,:));
legend({'UKF Matlab','UKF Simulink','Real'})

subplot(2,1,2)
plot(t,x(2,:),t,simulinkoutput(2,:),t,simulinkreal(2,:));
legend({'UKF Matlab','UKF Simulink','Real'})


