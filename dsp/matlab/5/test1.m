clc; clear; close all; 
nx1 = 0:7; nx2 = 0:15;
x1 = 2*nx1+3; x2 = sin(2*nx1*pi/16);
N1 = length(x1); N2 = length(x2);
N = N1+N2-1;
%% 直接调用线性卷积函数conv计算
y = conv(x1,x2);
%% 快速卷积法
xn1 = [x1 zeros(1, N-N1)]; %对x1(n)补零使得长度为N
xn2 = [x2 zeros(1, N-N2)]; %对x2(n)补零使得长度为N
Xn1 = fft(xn1); %调用快速算法fft求X1(k)=DTF[x1(n)]
Xn2 = fft(xn2); %调用快速算法fft求X2(k)=DTF[x2(n)]
Yn = Xn1.*Xn2; %求Y(k)=X1(k)X2(k)
yn = ifft(Yn); %调用快速逆算法ifft求y(n)=IDFT[Y(k)]
%计算误差
error = y-yn; 
figure(1);
stem(0:N-1,y,'fill','b','linewidth',1.0);
xlabel('\itn'); ylabel('Amplitude'); 
axis([0 N-1 0 60]);
title('{\ity}({\itn}) by conv()'); 
figure(2);
stem(0:N-1,yn,'fill','r','linewidth',1.0);
xlabel('\itn'); ylabel('Amplitude'); 
axis([0 N-1 0 60]);
title('{\ity}({\itn}) by FFT()');


