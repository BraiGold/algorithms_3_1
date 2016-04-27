% Procesado de los datos
[enemigos_x_con, tiempo_y_con, e_con, cant_con] = leer_datos_float('tiempos-exp5-con.txt');
[enemigos_x_sin, tiempo_y_sin, e_sin, cant_sin] = leer_datos_float('tiempos-exp5-sin.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;

n = size(enemigos_x_con);
ult = enemigos_x_con(n);
ultimo = ult(1);
primero = enemigos_x_con(1);


eje_x = primero:ultimo;
aux = eje_x+2;
pow = power(eje_x,aux);
eje_y = times(1/100000000,pow);


hold on;
ax = gca;
xlim([primero ultimo]);
%plot(eje_x,eje_y,'r'); %O(n * (n+2))
k=errorbar(enemigos_x_sin, tiempo_y_sin, e_sin, 'g')
h=errorbar(enemigos_x_con, tiempo_y_con, e_con);
set(get(k, 'Parent'), 'YScale', 'log');
set(get(h, 'Parent'), 'YScale', 'log');
hold off;
%'Complejidad O(n * (n+2))'
legend('Tiempo de ejecucion del algoritmo sin poda','Tiempo de ejecucion del algoritmo con poda','Location','northwest')
xlabel('Cantidad de Enemigos','FontSize',12);
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
title('Comparacion del algoritmo con poda y sin poda');
print('exp1', filetype);