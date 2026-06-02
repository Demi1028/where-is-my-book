clc;clear;close all;
f1 = 2;f2 = 2.02;f3 = 2.07;
fs = 10;Ts = 1/fs;

Tp1 = 25.6;
N1 = fs * Tp1;   % 采样点数
t1 = (0:N1-1)/fs;

x1 = sin(2*pi*f1*t1) + sin(2*pi*f2*t1) + sin(2*pi*f3*t1);

X1 = fft(x1);
f_axis1 = (0:N1-1)*(fs/N1);

x1_fft = fft(x1);
f_axis1 = (0:N1-1)*(fs/N1);

figure(1);
plot(f_axis1, abs(X1)/N1);
xlim([0 5]);
xlabel('频率 (Hz)');ylabel('幅度');
