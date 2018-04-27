M = [B A*B A^2*B A^3*B]
rank(M)

%polos desejados
p1=-2+2*sqrt(3);
p2=-2-2*sqrt(3);
p3=-10;
p4=-10;

J = [p1 0 0 0; 0 p2 0 0; 0 0 p3 0; 0 0 0 p4];
poly(J);

Phi = polyvalm(poly(J),A);

K = [0 0 0 1]*(inv(M))*Phi;