
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

width  =  1;                    %Cube size
length = 1;
height = 1;
L1=1
P1=[-0.25  0.25  0.25];
P2=[-0.25  0.25 -0.25];
P3=[-0.25 -0.25  0.25];
P4=[-0.25 -0.25 -0.25];

P5=[L1 -0.25  0.25];
P6=[L1 -0.25 -0.25];
P7=[L1  0.25 -0.25];
P8=[L1  0.25  0.25];

X = [P1(1) P4(1) P1(1) P8(1)  P7(1) P6(1);
     P2(1) P5(1) P2(1) P5(1)  P2(1) P5(1);
     P3(1) P8(1) P7(1) P6(1)  P3(1) P4(1);
     P4(1) P1(1) P8(1) P7(1)  P6(1) P3(1)];

Y = [P1(2) P4(2) P1(2) P8(2)  P7(2) P6(2);
     P2(2) P5(2) P2(2) P5(2)  P2(2) P5(2);
     P3(2) P8(2) P7(2) P6(2)  P3(2) P4(2);
     P4(2) P1(2) P8(2) P7(2)  P6(2) P3(2)];

Z =[P1(3) P4(3) P1(3) P8(3)  P7(3) P6(3);
     P2(3) P5(3) P2(3) P5(3)  P2(3) P5(3);
     P3(3) P8(3) P7(3) P6(3)  P3(3) P4(3);
     P4(3) P1(3) P8(3) P7(3)  P6(3) P3(3)];

C = [10 ; 2 ; 4 ; 10 ; 6 ;10];

X = X*length;
Y = Y*width;
Z = Z*height;

map = [zColor;yColor;xColor;CubeColor];
colormap(map);

hold on
cubo  = fill3(X,Y,Z,'b');
axis([-AL AL -AL AL -AL AL]);
grid on
box on