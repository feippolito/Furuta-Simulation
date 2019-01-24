function X=sigmas(x,P,c)
%Sigma points around reference point
%Inputs:
% x: reference point
% P: covariance
% c: coefficient
%Output:
% X: Sigma points
%P0 = gallery('moler',4)
A = c*chol(P,'lower')';
Y = x(:,ones(1,numel(x)));
X = [x Y+A Y-A];