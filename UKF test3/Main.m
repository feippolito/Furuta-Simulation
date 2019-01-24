n=2; %number of state
q=0.1; %std of process
r=0.1; %std of measurement
Q=q^2*eye(n); % covariance of process
R=r^2; % covariance of measurement
f=@stateTransition; % nonlinear state equations
h=@stateMeasurement; % measurement equation
s=[0;0]; % initial state
x=s+q*randn(2,1); %initial state % initial state with noise
P = eye(n); % initial state covraiance
N=size(input,1); % total dynamic steps
xV = zeros(n,N); %estmate % allocate memory
sV = zeros(n,N); %actual
zV = measurement';
u=input';
for k=1:N
z = zV(k); % measurments
sV(:,k)= s; % save actual state
zV(k) = z; % save measurment
[x, P] = ukf(f,x,P,h,z,Q,R,u); % ekf
xV(:,k) = x; % save estimate
s = f(s,u) + q*randn(2,1); % update process
end
t=0:Ts:0
for k=1:n % plot results
subplot(n,1,k)
plot(1:N, sV(k,:), '-', 1:N, xV(k,:), '--')
end