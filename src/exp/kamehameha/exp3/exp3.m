% Procesado de los datos
[enemigos_x_con, tiempo_y_con, e_con, cant_con] = leer_datos_float('tiempos-exp3-conPoda.txt');
[enemigos_x_sin, tiempo_y_sin, e_sin, cant_sin] = leer_datos_float('tiempos-exp3-sinPoda.txt');


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
pow = power(eje_x_con,aux);
eje_y = pow;


hold on;
ax = gca;
xlim([primero ultimo]);
plot(eje_x,eje_y,'r'); %O(n * (n+2))
errorbar(enemigos_x_sin, tiempo_y_sin, e_sin)
h=errorbar(enemigos_x_con, tiempo_y_con, e_con);
set(get(h, 'Parent'), 'YScale', 'log');
hold off;
legend('Complejidad O(n * (n+2))','Tiempo de ejecucion del algoritmo','Location','northwest')
xlabel('Cantidad de Enemigos','FontSize',12);
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
print('exp1', filetype);