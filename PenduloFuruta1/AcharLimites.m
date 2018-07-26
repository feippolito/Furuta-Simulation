Mtheta2=zeros(9300,1);
Mdtheta1=zeros(9300,1);
Mdtheta2=zeros(9300,1);
Memax=zeros(9300,1);
u=zeros(9300,1);
erro=zeros(9300,1);
y=zeros(9300,1);

K(1)=0;
AA = A -B*K;

i=1;

for(theta2o = 0:1:20)
    theta2o=theta2o*pi/180;
    for(dtheta1o = -10:1:10)
        for(dtheta2o = -10:1:10)
            BB = [theta1o;theta2o;dtheta1o;dtheta2o];
            [x,z,t] = step(AA,BB,AA,BB);
            U=K*x';
            Emax = max(abs(U));
            Mtheta2(i)= theta2o;
            Mdtheta1(i) = dtheta1o;
            Mdtheta2(i)= dtheta2o;
            Memax(i) = Emax;
            if(Emax>15)
                y(i)=0;
            else
                y(i)=1;
            end
            
            
%             u(i) = K(2)*theta2o+K(3)*dtheta1o+K(4)*dtheta2o;
%             erro(i) = (M2(i,4) - abs(u(i)));
%             
            i=i+1
        end
    end
end

M2=[Mtheta2 Mdtheta1 Mdtheta2 Memax y];
