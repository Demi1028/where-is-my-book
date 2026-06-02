clc; clear; close all; 
T = 0.001; fc =1/T; %抽样频率
ap=1; as=30; fp = 200; fs = 400; %数字滤波器的技术指标要求
wp = 2*pi*fp/fc; %数字滤波器通带截止频率
ws = 2*pi*fs/fc;  %数字滤波器阻带截止频率
% * * * * *双线性变换法* * * * *
%要求数字滤波器技术指标转化成模拟滤波器技术指标
Wanp = 2*fc*tan(wp/2);     %通带截止频率
Wans = 2*fc*tan(ws/2);      %阻带截止频率
%设计模拟滤波器阶数和截止频率
[N,Wanc]=buttord(Wanp,Wans,ap,as,'s');
[b,a]=butter(N,Wanc,'s');  %设计模拟滤波器系统函数Ha(s)
[B1,A1]=bilinear(b,a,fc); %用双线性变换法设计数字滤波器系统函数Hz
[H1,w1]=freqz(B1,A1,'whole'); %求数字滤波器的频率响应
figure(1);
plot(w1*fc/2/pi,20*log10(abs(H1)));
xlabel('频率 Hz'); ylabel('幅值 (dB)');
title('双线性的低通数字滤波器');
