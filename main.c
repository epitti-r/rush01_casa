#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c);
void	muestra_numeros(int **numeros);
int		chequear_numeros(char **argv);
int		**leer_numeros(char **argv);
int		**solucion_sudoku(int **numeros);

int		main(int argc, char **argv)
{
	int **numeros;
	int **solucion;

	if (argc == 2)
	{
		numeros = leer_numeros(&argv[1]);
		if (chequear_numeros(&argv[1]) == 0 || (!numeros))
            write(2, "Error\n", 6);		
		else
		{
			solucion = solucion_sudoku(numeros);
            muestra_numeros(numeros);
			free(numeros);
			free(solucion);
		}
    }
	else
		write(2, "Error\n", 6);
	return (0);
}