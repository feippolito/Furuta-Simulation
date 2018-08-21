
interval = 0.001;               %Interval (seconds)
view(135,45)                    %Starting view
AL = 5;                         %Define graph axis limits

la = 230.45e-3;

xColor = [ 0 0 0.6];
yColor = [ 0 0.6 0];
zColor = [ 0.6 0 0];            %Axis/Faces Colors
CubeColor = [0.2 0.2 0.2];      %Cube Color

s=5;                            %Scatter size
SI=5;                           %Scatter interval
scatterColorx = xColor;         %Scatter color x axis
scatterColory = yColor;         %Scatter color y axis
scatterColorz = zColor;         %Scatter color z axis

FAL = 5;                        %Fixed axis lenght
CAL = 2;                        %Cube  axis lenght

Xxaxis=[0;CAL];                 
Yxaxis=[0;0];
Zxaxis=[0;0];

Xyaxis=[0;0];
Yyaxis=[0;CAL];                
Zyaxis=[0;0];    

Xzaxis=[0;0];
Yzaxis=[0;0];
Zzaxis=[0;CAL];                 

width  =  1;                  
length = 1;
height = 1;


L1=2;
W1=0.25;

L2=1.5;
W2=0.25;

%Horizontal arm

P1=[-W1  W1  W1];
P2=[-W1  W1 -W1];
P3=[-W1 -W1  W1];
P4=[-W1 -W1 -W1];

P5=[L1 -W1  W1];
P6=[L1 -W1 -W1];
P7=[L1  W1 -W1];
P8=[L1  W1  W1];

Xh=[P1(1) P3(1) P4(1) P2(1);
    P2(1) P4(1) P6(1) P7(1);
    P6(1) P7(1) P8(1) P5(1);
    P7(1) P8(1) P1(1) P2(1);
    P1(1) P8(1) P5(1) P3(1);
    P3(1) P4(1) P6(1) P5(1)]';

Yh=[P1(2) P3(2) P4(2) P2(2);
    P2(2) P4(2) P6(2) P7(2);
    P6(2) P7(2) P8(2) P5(2);
    P7(2) P8(2) P1(2) P2(2);
    P1(2) P8(2) P5(2) P3(2);
    P3(2) P4(2) P6(2) P5(2)]';

Zh=[P1(3) P3(3) P4(3) P2(3);
    P2(3) P4(3) P6(3) P7(3);
    P6(3) P7(3) P8(3) P5(3);
    P7(3) P8(3) P1(3) P2(3);
    P1(3) P8(3) P5(3) P3(3);
    P3(3) P4(3) P6(3) P5(3)]';

% Vertical arm

p1=[L1     W2 W2];
p2=[L1+2*W2  W2 W2];
p3=[L1+2*W2 -W2 W2];
p4=[L1    -W2 W2];

p5=[L1     W2 -L2];
p6=[L1+2*W2  W2 -L2];
p7=[L1+2*W2 -W2 -L2];
p8=[L1    -W2 -L2];

Xv=[p1(1) p2(1) p3(1) p4(1);
    p3(1) p4(1) p8(1) p7(1);
    p8(1) p7(1) p6(1) p5(1);
    p5(1) p8(1) p4(1) p1(1);
    p1(1) p2(1) p6(1) p5(1);
    p6(1) p7(1) p3(1) p2(1)]';

Yv= [p1(2) p2(2) p3(2) p4(2);
     p3(2) p4(2) p8(2) p7(2);
     p8(2) p7(2) p6(2) p5(2);
     p5(2) p8(2) p4(2) p1(2);
     p1(2) p2(2) p6(2) p5(2);
     p6(2) p7(2) p3(2) p2(2)]';

Zv=  [p1(3) p2(3) p3(3) p4(3);
      p3(3) p4(3) p8(3) p7(3);
      p8(3) p7(3) p6(3) p5(3);
      p5(3) p8(3) p4(3) p1(3);
      p1(3) p2(3) p6(3) p5(3);
      p6(3) p7(3) p3(3) p2(3)]';
 
C = [10 ; 2 ; 4 ; 10 ; 6 ;10];

Xh = Xh*length;
Yh = Yh*width;
Zh = Zh*height;

map = [zColor;yColor;xColor;CubeColor];
colormap(map);

hold on
Harm  = fill3(Xh,Yh,Zh,'b');           %Horizontal arm
Varm  = fill3(Xv,Yv,Zv,'g');           %Vertical arm (Pendulum)
axis([-AL AL -AL AL -AL AL]);

grid on
box on

%% Update
phi =0;
for t=1:100*180
    
    

         
    set(Harm,'XData',Xh);
    set(Harm,'YData',Yh);
    set(Harm,'ZData',Zh);
    set(Harm,'FaceVertexCData',C);
    
    
    drawnow
    pause(0.5); 
end