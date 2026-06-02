clc; clear; close all; 
x1 = [1,-1,2,1]; x2 = [2,0,-1,1,2];
ylin = conv(x1,x2);
figure(1);
stem(ylin,'fill','r','linewidth',1.0);
xlabel('\itn'); ylabel('{\ity}({\itn})'); axis([0 8 -5 6]);
title('{\ity}({\itn})={\itx}_1({\itn})*{\itx}_2({\itn})'); 
