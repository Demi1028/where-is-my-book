clc; clear; close all; 
x1 = [1,-1,2,1,0]; x2 = [2,0,-1,1,2];
y1 = circonvtim(x1,x2,5);%5点循环/圆周卷积
%y2 = circonvtim(x1,x2,6);%6点循环/圆周卷积
y3 = circonvtim(x1,x2,7);%7点循环/圆周卷积
y4 = circonvtim(x1,x2,8);%8点循环/圆周卷积
figure(1);
stem(y1,'fill','g','linewidth',1.0);
xlabel('\itn'); ylabel('{\ity}_1({\itn})'); axis([0 8 -5 6]);
title('{\ity}_1({\itn})={\itx}_1({\itn}) ⑤{\itx}_2({\itn})'); 
%subplot(4,1,2); stem(y2,'fill','b','linewidth',1.0);
%xlabel('\itn'); ylabel('{\ity}_2({\itn})'); axis([1 8 0 15]);
%title('{\ity}_2({\itn})={\itx}_1({\itn}) ⑥{\itx}_2({\itn})'); 
figure(2);
stem(y3,'fill','r','linewidth',1.0);
xlabel('\itn'); ylabel('{\ity}_3({\itn})'); axis([0 8 -5 6]);
title('{\ity}_3({\itn})={\itx}_1({\itn}) ⑦{\itx}_2({\itn})'); 
figure(3);
stem(y4,'fill','m','linewidth',1.0);
xlabel('\itn'); ylabel('{\ity}_4({\itn})'); axis([0 9 -5 6]);
title('{\ity}_4({\itn})={\itx}_1({\itn}) ⑧{\itx}_2({\itn})'); 

function y=circonvtim(x1,x2,N)
n=0:N-1;
x1=[x1,zeros(1,N-length(x1))];
x2=[x2,zeros(1,N-length(x2))];
x3=x2(mod(-n,N)+1);
for m=0:N-1
    x4=cirshftt(x3,m,N);
    x5=x1.*x4;
    y(m+1)=sum(x5);
end
end


function y=cirshftt(x,m,N)
if length(x)>N
    error
    ('N must be >=the length of x');
end
x=[x,zeros(1,N-length(x))];
n=0:N-1;
n=mod(n-m,N);
y=x(n+1);
end