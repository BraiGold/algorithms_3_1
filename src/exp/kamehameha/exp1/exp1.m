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
aux = eje_x+2;
pow = power(eje_x,aux);
eje_y = times(1/10000000000,pow);


hold on;
ax = gca;
xlim([primero ultimo]);
plot(eje_x,eje_y,'r'); %O(n * (n+2))

h=errorbar(enemigos_x, tiempo_y, e);
set(get(h, 'Parent'), 'YScale', 'log');
hold off;
legend('Complejidad O(n * (n+2))','Tiempo de ejecucion del algoritmo','Location','northwest')
xlabel('Cantidad de Enemigos','FontSize',12);
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
title('Tiempo de ejecucion en funcion de la cantidad de enemigos');
print('exp1', filetype);