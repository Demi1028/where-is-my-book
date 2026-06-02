clc; clear; close all; 
f1 = 2; f2 = 2.02; f3 = 2.07; %信号的频率成分
fs = 10; Ts = 1/fs; %抽样频率和抽样间隔
Tp1 = 102.4; %信号的记录时长
N = Tp1/Ts; F = fs/N; %频谱分辨率
n = 0:N-1; 
xa = sin(2*pi*f1*n/fs)+sin(2*pi*f2*n/fs)+sin(2*pi*f3*n/fs); %信号
% %试用DTFT进行频谱分析
k1 = 0:999;
X_DTFT = xa*(exp(-1i*2*pi/length(k1))).^(n'*k1);
X_abs = abs(X_DTFT);
X_angle = angle(X_DTFT);
% %试用DFT进行频谱分析
Xa = DFTfor(xa);
Xa_abs = abs(Xa);
Xa_angle = angle(Xa);
Xa_fft = fft(xa);
Xa_absfft = abs(Xa_fft); 
Xa_anglefft = angle(Xa_fft);

figure(1);
subplot(3,1,1); plot(n/fs, xa,'-m','linewidth',1.0); hold on;
xlabel('\itn'); ylabel('幅度'); title('时域波形'); 
subplot(3,1,2);
plot(0:(fs)/(length(k1)-1):fs,X_abs/N,'-g','linewidth',1.0); hold on;
xlim([7.8,8.5]);
plot(0:(fs)/(N-1):fs, Xa_abs/N, '-.r', 'Linewidth', 1.5); hold on;
xlim([7.8,8.5]);
plot(0:(fs)/(N-1):fs, Xa_absfft/N,'--b', 'Linewidth', 1.0); hold on;
xlim([7.8,8.5]);
legend('DTFT','DFTfor','FFT');
xlabel('{\it{f}}_{\it{s}}'); ylabel('幅度'); title('幅度谱'); 
subplot(3,1,3);
plot(0:(fs)/(length(k1)-1):fs,X_angle/pi,'-g','linewidth',1.0); hold on;
plot(0:(fs)/(N-1):fs, Xa_angle/pi, '-.r', 'Linewidth', 1.5); hold on;
plot(0:(fs)/(N-1):fs, Xa_anglefft/pi,'--b', 'Linewidth', 1.0); hold on;
legend('DTFT','DFTfor','FFT');
xlabel('{\it{f}}_{\it{s}}'); ylabel('相位'); title('相位谱');

function X = DFTfor(xn)
%利用for循环方法计算DFT
%xn为输入序列x(n)
%X为X = DFT[x(n)]
N = length(xn); % 输入序列的长度
X = zeros(1,N); %初始化
for k = 0: N-1
    for n = 0:N-1
        %按照定义计算频谱X(k)
        X(1, k+1) = X(1, k+1)+xn(n+1)*exp(-1i*2*pi/N*n*k);
    end
end
end