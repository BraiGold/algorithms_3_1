% Procesado de los datos
[t_x, tiempo_y, e, cant] = leer_datos_float('tiempos-kaioken.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;

n = size(t_x);
ult = t_x(n);
ultimo = ult(1);
primero = t_x(1);


eje_x = primero:ultimo;
l = log2 (eje_x);
ll = times(eje_x,l);
eje_y = times(1/13000000,ll);


hold on;
ax = gca;
xlim([primero ultimo]);
plot(eje_x,eje_y,'r'); %O(n log n)

errorbar(t_x, tiempo_y, e);
hold off;
legend('Complejidad O(n log n)','Tiempo de ejecucion del algoritmo','Location','northwest')
xlabel('Cantidad de Guerreros','FontSize',12);
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
title('Tiempo de ejecucion en funcion de n')
%set(get(h, 'Parent'), 'YScale', 'log');
print('kaioken', filetype);