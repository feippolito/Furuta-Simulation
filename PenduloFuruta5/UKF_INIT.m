N=size(input,1);
x_UKF=zeros(2,N);
u=input';
x = zeros(2,N);
yt=measurement';
L=2;        % Lenght of state vector
alphaC = 1; % Primary scaling parameter
betaC = 2;  % Secondary scaling parameter
kappa = 0;  % Tertiary scaling parameter
lambda = alphaC^2*(L+kappa) - L;
wm = ones(2*L + 1,1)*1/(2*(L+lambda));
wc = wm;
wm(1) = lambda/(lambda+L);
wc(1) = lambda/(lambda+L) + 1 - alphaC^2 + betaC;
T=0.001;

Q = diag([2e-8,2e-8]);
R = 2e-8;
P0 = eye(2)*0.001;

%x = zeros(2,2); % Initialize size of state estimate for all actual time and past time
%x(:,1) = [0; 0]; % Set initial state estimate
%yt = zeros(2, 2);

P=P0;

UKF_RECURSIVE