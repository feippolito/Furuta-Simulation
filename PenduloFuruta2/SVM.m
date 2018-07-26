X=M2(:,1:3);
y=M2(:,5);

SVMModel = fitcsvm(X,y,'KernelFunction','RBF','KernelScale','auto')

%classOrder = SVMModel.ClassNames

% sv = SVMModel.SupportVectors;
% figure
% gscatter(X(:,1),X(:,2),y)
% hold on
% plot(sv(:,1),sv(:,2),'ko','MarkerSize',10)
% legend('versicolor','virginica','Support Vector')
% hold on

a = SVMModel.Alpha;
b = SVMModel.Bias;
ys = SVMModel.SupportVectorLabels;
xs = SVMModel.SupportVectors;
sigma = SVMModel.KernelParameters.Scale;

theta2o=14*pi/180;
dtheta1o=8;
dtheta2o=-15;

xt = [theta2o, dtheta1o, dtheta2o];
out = 0;

for i = 1 : length(ys)
    x1 = xs(i,:);
    G = exp((-1/sigma^2)*(xt-x1)*(xt-x1)');
    out1 = a(i)*ys(i)*G;
    out = out + out1;
end

output = out
% plot(xt(1),xt(2),'x','MarkerSize',10)