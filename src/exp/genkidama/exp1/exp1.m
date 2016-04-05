% Procesado de los datos
[enemigos_x, tiempo_y, e, cant] = leer_datos_float('tiempos-exp1.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;

hold on;
%axis([tam_x_a(length(tam_x_a)),tam_x_a(1)]);%esto es para que el eje x sea del tamaño de la cantidad de datos y no haya bordes blancos ocupando espacio
errorbar( enemigos_x, tiempo_y, e);
xlabel('Cantidad de Enemigos','FontSize',12);
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
%set(get(h, 'Parent'), 'YScale', 'log');
hold off;
print('exp1', filetype);