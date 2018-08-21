view(135,45)                    %Starting view
AL = 5;                         %Define graph axis limits

L1=3;
L2=1;

Xh=[0 ; L1]';
Yh=[0 ; 0]';
Zh=[0 ; 0]';

Xv=[Xh(2) ; L1]';
Yv=[Yh(2) ; 0]';
Zv=[Zh(2) ; -L2]';

hold on
Harm  = fill3(Xh,Yh,Zh,'b'); 
Varm  = fill3(Xv,Yv,Zv,'g'); 

s=5;
M=scatter3(Xv(2),Yv(2),Zv(2),s,'filled','MarkerFaceColor','b','MarkerEdgeColor','k')

axis([-AL AL -AL AL -AL AL]);

phi =pi/9;
theta =pi;
for t=1:100*180
    
    phi=phi+1/180*pi;
    theta =theta+1/180*pi;
    
    Xh(2)= L1*cos(phi);
    Yh(2)=L1*sin(phi);
    
    Xva = 0;
    Yva = L2*cos(theta);
    Zva = L2*sin(theta);
    
    Xvb = Xva*cos(phi)-Yva*sin(phi)+L1*cos(phi);
    Yvb = Xva*sin(phi)+Yva*cos(phi) + L1*sin(phi);
    Zvb = Zva;
        
    
    Xv=[Xh(2);Xvb]';
    Yv=[Yh(2);Yvb]';
    Zv=[ 0   ;Zvb]';
    
    
    set(Harm,'XData',Xh);
    set(Harm,'YData',Yh);
    set(Harm,'ZData',Zh);
    %set(Harm,'FaceVertexCData',C);
    
    set(Varm,'XData',Xv);
    set(Varm,'YData',Yv);
    set(Varm,'ZData',Zv);
    %set(Varm,'FaceVertexCData',C);
    
    set(M,'XData',Xv(2));
    set(M,'YData',Yv(2));
    set(M,'ZData',Zv(2));

    
    drawnow
    pause(0.005); 
end