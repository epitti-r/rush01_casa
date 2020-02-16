#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	muestra_numeros(int **numeros)
{
	int filas;
	int columnas;

	filas = 0;
	while (filas < 4)
	{
		columnas = 0;
		while (columnas < 4)
		{
			ft_putchar(numeros[filas][columnas] + '0');
			if (columnas != 3)
				ft_putchar(' ');
			columnas++;
		}
		ft_putchar('\n');
		filas++;
	}
}

int		chequear_numeros(char **argv)
{
	int pos;

	pos = 0;
	while (argv[0][pos])
	{
        if ((pos + 1) % 2 == 0) // verificamos los multiplos de 2, deben ser espacios o será error
        {
            if (argv[0][pos] != ' ') // si no es espacio, error
                return (0);
        }
        else if (argv[0][pos] > '4' || argv[0][pos] < '1') // verificamos que los otros sean números entre 1 y 4
            return (0);
        pos++;
	}
	if (pos != 31) // si tiene más de 31 caracteres, será error
		return (0);
	return (1);
}

int		**leer_numeros(char **argv)
{
	int filas;
	int columnas;
	int **numeros;
	int pos;

	filas = 0;
	pos = 0;
	numeros = (int **)malloc(sizeof(int *) * 4 + 1);
	while (filas < 4)
	{
		numeros[filas] = (int *)malloc(sizeof(int) * 4 + 1);
		columnas = 0;
		while (columnas < 4)
		{	
		    if (argv[0][pos] >= '1' && argv[0][pos] <= '4')
			{
        	    numeros[filas][columnas] = argv[0][pos] - 48; // convertimos el char en entero restando el equivalente al char '0' ascii
				columnas++;
			}
			pos++;
		}
		filas++;
	}
	return (numeros);
}

int		**solucion_sudoku(int **numeros)
{
    int **solucion;
	int filas;
	int columnas;

	filas = 0;
	solucion = (int **)malloc(sizeof(int *) * 4 + 1);
	while (filas < 4)
	{
		solucion[filas] = (int *)malloc(sizeof(int) * 4 + 1);
		columnas = 0;
		while (columnas < 4)
		{	
       	    solucion[filas][columnas] = numeros[filas][columnas]; // copia el contenido de "numeros" en "solucion". Hay que modificar con la solucion real
			columnas++;
		}
		filas++;
	}    
    return (solucion);
}