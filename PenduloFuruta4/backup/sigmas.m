function X=sigmas(x,P,c)
A = c*chol(P)';
Y = x(:,ones(1,numel(x)));
X = [x Y+A Y-A];