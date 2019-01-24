function displayBusdata(block,~)

t =  block.CurrentTime;
phi = block.OutputPort(1).Data.signal1;
theta =block.OutputPort(1).Data.signal2;

L1=3;
L2=2;

Xh=[0 ; L1]';
Yh=[0 ; 0]';
Zh=[0 ; 0]';

Xv=[Xh(2) ; L1]';
Yv=[Yh(2) ; 0]';
Zv=[Zh(2) ; -L2]';
AL = 5; 
axis([-AL AL -AL AL -AL AL]);

if(t == 0)
    view(135,30)                    %Starting view
                            %Define graph axis limits
    grid on
    hold on
    Harm  = fill3(Xh,Yh,Zh,'b','tag','Harm'); 
    Varm  = fill3(Xv,Yv,Zv,'g','tag','Varm'); 

    s=5;
    M=scatter3(Xv(2),Yv(2),Zv(2),s,'filled','MarkerFaceColor','b','MarkerEdgeColor','k','tag','M')

else
    
    Harm=findobj('Tag','Harm');
    Varm=findobj('Tag','Varm');
    M = findobj('Tag','M');
    
    TXT=title('Time: ')   
    set(TXT,'String',t);
    
    Xh(2)= L1*cos(phi);
    Yh(2)=L1*sin(phi);

    Xva = 0;                
    Yva = L2*sin(theta);    
    Zva = -L2*cos(theta);   

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

    %       if(rem(t,5)==0) 
    %           M=scatter3(Xv(2),Yv(2),Zv(2),s,'filled','MarkerFaceColor','r','MarkerEdgeColor','k');
    %       end

    set(M,'XData',Xv(2));
    set(M,'YData',Yv(2));
    set(M,'ZData',Zv(2));

    drawnow;

    %     pause(0.0005); 
end
