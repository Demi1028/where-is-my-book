clc; clear; close all; 
T = 0.001; fc =1/T; %抽样频率
ap=1; as=10; wp = 0.2*pi; ws = 0.3*pi; %数字滤波器的技术指标要求
% * * * * *采用冲激响应不变法* * * * *
%要求数字滤波器技术指标转化成模拟滤波器技术指标
Wanp = wp*fc;     %通带截止频率
Wans = ws*fc;      %阻带截止频率
%设计模拟滤波器阶数和截止频率
[N,Wanc]=buttord(Wanp,Wans,ap,as,'s');
[b,a]=butter(N,Wanc,'s');  %设计模拟滤波器系统函数Ha(s)
[B1,A1]=impinvar(b,a,fc); %用冲激响应不变法设计数字滤波器系统函数Hz
[H1,w1]=freqz(B1,A1,'whole'); %求数字滤波器的频率响应
figure(1);
plot(w1*fc/2/pi,20*log10(abs(H1)));
xlabel('频率 Hz'); ylabel('幅值 (dB)');
title('冲激响应不变法设计的低通数字滤波器');
figure(2);
plot(w1/pi, angle(H1), '-r', 'Linewidth', 1.0); xlabel('\omega/pi'); ylabel('相位'); 
title('相位谱');
