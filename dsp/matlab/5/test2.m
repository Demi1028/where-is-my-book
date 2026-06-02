clc; clear; close all; 
nx = 0:200; nh = 0:3;
x = nx; h = [1,0,3,7];
K = length(x); M = length(h);
L = 5;  % 每一小段xi的长度为7
N = L+M-1; %每一小段跟h卷积后的长度
 
%% 调用线性卷积函数conv计算
y_conv = conv(x,h); 
%% 调用重叠相加法函数overaddfft计算
%y_over = overaddfft(x,h,L); 
%% 重叠相加法by meilinhe
y_meilinhe = meilinhe(x,h,K,M,L,N); 

figure(1);
stem(0:length(y_meilinhe)-1,y_meilinhe,'fill','r','linewidth',1.0);
xlabel('\itn'); ylabel('Amplitude'); 
axis([0 length(y_conv)-1 0 2500]);
title('{\ity}({\itn}) = {\itx}({\itn})*{\ith}({\itn}) by meilinhe()');

function y_meilinhe=meilinhe(x,h,K,M,L,N)
T = ceil(K/L); %x可以划分的段数
x1 = [x, zeros(1,L*T-K)]; %补零使x之能够刚好分成整数段
x2 = reshape(x1, L, T)'; %变形成矩阵，每一行恰好是分段后每一段xi的值
x3 = [x2, zeros(T, N-L)]; %补零为fft作准备
h1 = [h zeros(1,N-M)];  %补零让h与x同等长度
h2 = repmat(h1,T,1); %复制h每一行，让h与x变成同等维度的矩阵
X = fft(x3,[],2); %对x的每一行进行傅里叶变换
H = fft(h2,[],2); %对h的每一行进行傅里叶变换
Y = X.*H; %时域卷积对应频域乘积
y = ifft(Y,[],2); %对Yn的每一行进行傅里叶逆变换
%%接下来，对重叠部分相加
Ny = (T-1)*L+N; %矩阵补零后的长度
yy = zeros(T,Ny); %对y序列前后补零后，重新存入yy矩阵，初始化yy矩阵
for i = 1:T %分行计算
    ix = (i-1)*L; %在原来y第i行序列之前补零的个数
    yy(i, :) =[zeros(1, ix), y(i, 1:N), zeros(1, Ny-ix-N)]; %对yn序列前后补零，存入yy矩阵
end
y_meilinhe = sum(yy); %对yy矩阵的每列叠加求和
end
