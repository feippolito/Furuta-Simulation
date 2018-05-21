Mtheta2=0;
Mdtheta1=0;
Mdtheta2=0
Memax=0;
i=0
for(theta2o = 0:1:14)
    for(dtheta1o = -2:1:2)
        for(dtheta2o = -2:1:2)
            sim('LinearMF');
            Emax = max(WSmotor.data(:));
            if(Emax <=12 )
                Mtheta2=[Mtheta2 theta2o];
                Mdtheta1=[Mdtheta1 dtheta1o];
                Mdtheta2=[Mdtheta2 dtheta2o];
                Memax=[Memax Emax]
            end
            i=i+1
        end
    end
end
