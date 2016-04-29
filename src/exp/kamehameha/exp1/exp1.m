% Procesado de los datos
[enemigos_x, tiempo_y, e, cant] = leer_datos_float('tiempos-exp1.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;

n = size(enemigos_x);
ult = enemigos_x(n);
ultimo = ult(1);
primero = enemigos_x(1);


eje_x = primero:ultimo;
cuadrado = times(eje_x,eje_x);
fact = factorial(eje_x);
aux = times(fact,cuadrado);
eje_y = times(1/100000000,aux);


hold on;
ax = gca;
xlim([primero ultimo]);
plot(eje_x,eje_y,'r'); %O(n * (n+2))

h=errorbar(enemigos_x, tiempo_y, e);
set(get(h, 'Parent'), 'YScale', 'log');
hold off;
legend('Complejidad O(n! * (n*n))','Tiempo de ejecucion del algoritmo','Location','northwest')
xlabel('Cantidad de Enemigos','FontSize',12);
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
title('Tiempo de ejecucion en funcion de la cantidad de enemigos');
print('exp1', filetype);