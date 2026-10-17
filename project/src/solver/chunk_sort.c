/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:27:47 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/17 02:51:23 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

/* Get maximum number position*/
int	get_max_pos(t_list *stack)
{
	int	max_val;
	int	max_pos;
	int	i;

	if (!stack)
		return (-1);
	i = 0;
	max_pos = 0;
	max_val = (*(int *)stack->content);
	while (stack)
	{
		if ((*(int *)stack->content) > max_val)
		{
			max_val = *(int *)stack->content;
			max_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (max_pos);
}

/*
// 1. DEFINICIÓN DE BLOQUES
// Queremos saber qué rango de valores aceptamos ahora mismo.
size_chunk = calculate_size_chunk(size) // Ej: size / 6
limit_sup = size_chunk

	while (*(int *)stack->content)
	{
	    num_top = value_on top_a();

    // CASO A: El número está dentro del bloque actual
	if (num_top <= sorted[limit_sup]);
		do_operation(pb);
        
        // Optimización clave (para que B quede con forma de donut):
        // Si además el número es de la mitad inferior de ese mismo bloque:
		 if (num_top <= sorted[limit_sup - (size_chunk / 2)])
			do_operation(rb); // Lo mandamos al fondo de B
            
        // Si ya hemos mandado a B suficientes números como para llenar este bloque,
        // ampliamos el límite al siguiente bloque:
        SI tamanyo_de_B >= limite_superior Y limite_superior + tamanyo_chunk < size:
            limit_sup = limit_sup + size_chunk;

    // CASO B: El número es más grande que el bloque actual
	else
		do_operation(ra); // No nos sirve todavía; lo rotamos para buscar otro
	}
*/

/*
	A se ha quedado vacía. B tiene todos los números, pero no están mezclados al azar:
	los más pequeños de todos están al fondo de $B$, los medianos por en medio, y los
	más grandes arriba del todo.
*/

/*
MIENTRAS la pila B no esté vacía:
    // 1. Localizar el elemento con el valor más alto que queda en B
    posicion_del_maximo = buscar_posicion_del_maximo_en_B()
    tamanyo_actual_B = longitud_de_B()

    // 2. Llevar ese máximo a la cima de B por el camino más corto
    SI posicion_del_maximo <= (tamanyo_actual_B / 2):
        // Está en la mitad superior: rotar hacia arriba
        REPETIR posicion_del_maximo VECES:
            EJECUTAR(rb)
    SINO:
        // Está en la mitad inferior: rotar hacia abajo (reverse rotate)
        pasos = tamanyo_actual_B - posicion_del_maximo
        REPETIR pasos VECES:
            EJECUTAR(rrb)

    // 3. Ya está en el tope de B: lo devolvemos a A
    EJECUTAR(pa)
FIN MIENTRAS
*/