function [y,Y,P,Y1]=ut(f,X,Wm,Wc,n,R,u)
    L=size(X,2);
    y=zeros(n,1);
    Y=zeros(n,L);
    for k=1:L
        Y(:,k)=f(X(:,k),u(:,k));
        y=y+Wm(k)*Y(:,k);
    end
    Y1=Y-y(:,ones(1,L));
    P=Y1*diag(Wc)*Y1'+R;
