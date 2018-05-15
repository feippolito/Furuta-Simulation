M = [B A*B A^2*B A^3*B]
rank(M)

%polos desejados
p1=-5;
p2=-20;
p3=-30;
p4=-40;

J = [p1 0 0 0; 0 p2 0 0; 0 0 p3 0; 0 0 0 p4];
poly(J);

Phi = polyvalm(poly(J),A);

K = [0 0 0 1]*(inv(M))*Phi;