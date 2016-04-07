% Procesado de los datos
[t_x, tiempo_y, e, cant] = leer_datos_float('tiempos-kaioken.txt');


% Creación de los gráficos
filetype='-dpng';
%mkdir('graficos');
figure;

n = size(t_x);
ult = t_x(n);
ultimo = ult(1);
disp('ultimo = ');
disp(ultimo);
primero = t_x(1);

disp('primero = ');
disp(primero);


eje_x = primero:ultimo;
l = log2 (eje_x);
ll = times(eje_x,l);
eje_y = times(1/13000000,ll);


hold on;
ax = gca;
xlim([primero ultimo]);
%set(ax, 'XLim', [primero ultimo]);%esto es para que el eje x sea del tamaño de la cantidad de datos y no haya bordes blancos ocupando espacio
plot(eje_x,eje_y,'r'); %O(n log n)


errorbar(t_x, tiempo_y, e);
hold off;
legend('Complejidad O(n log n)','Tiempo de ejecucion del algoritmo','Location','northwest')
xlabel('Valor de n','FontSize',12);
ylabel('Tiempo de ejecucion en segundos','FontSize',10);
%set(get(h, 'Parent'), 'YScale', 'log');
print('kaioken', filetype);