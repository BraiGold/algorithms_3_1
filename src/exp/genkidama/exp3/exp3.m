% Procesado de los datos
[casos_x, tiempo_y, e, cant] = leer_datos_float('tiempos-exp3.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;


hold on;
bar(casos_x,tiempo_y,0.5);
ax = gca;
set(ax, 'XTick', [1 2 3 4]);
set(ax, 'XTickLabel', {'Distancia=2 T=4','Distancia=2 T=50','Distancia=50 T=4','Distancia=50 T=50'});
 

ylabel('Tiempo de ejecucion en segundos','FontSize',10);
hold off;
print('exp3', filetype);