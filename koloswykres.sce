clear
clc
clf
x=0:0.1:2
y=cos(2*x)
plot(x,y)
title("wykres")
xlabel('x')
ylabel('y')

y2=x^2-x+1
plot(x,y2,'r')
legend('f=cos(2*x)','f=x^2-x+1')
xgrid()

