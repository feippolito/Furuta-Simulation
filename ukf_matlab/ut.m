function [y,Y,P,Y1]=ut(f,X,Wm,Wc,n,R)
L=size(X,2);
y=zeros(n,1);
Y=zeros(n,L);
for k=1:L
    X
    Y(:,k)=f(X(:,k));
    y=y+Wm(k)Y(:,k);
end
Y1=Y-y(:,ones(1,L));
P=Y1diag(Wc)Y1'+R;