n=2; %number of state
q=2e-8;
r=2e-8;
Q=eye(n)*2e-8; % covariance of process
R=2e-8; % covariance of measurement
f=@stateTransition; % nonlinear state equations
h=@stateMeasurement; % measurement equation
s=[0;0]; % initial state
x=s%+q*randn(n,1); %initial state % initial state with noise
P = eye(n); % initial state covraiance
N=size(input,1); % total dynamic steps
xV = zeros(n,N); %estmate % allocate memory
sV = zeros(n,N); %actual
u = input';
zV = measurement';
for k=1:N
    z = zV(k)
    sV(:,k)= s; % save actual state
    [x, P] = ukf(f,x,P,h,z,Q,R,u); % ek
    xV(:,k) = x; % save estimate
    s = f(s,u)% + q*randn(n,1); % update process
end
for k=1:2 % plot results
    subplot(3,1,k)
    plot(1:N, sV(k,:), '-', 1:N, xV(k,:), '--')
end