/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 17:02:28 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/14 13:52:42 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKER_H
# define STACKER_H

# include <stdlib.h>
# include "../../libft/libft.h"

typedef struct s_state
{
	t_list	*a;
	t_list	*b;
}	t_state;

typedef enum e_operation
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_operation;

/* stacker */
void	fill_state(int *nums, int len, t_state *state);
void	stack_operate(t_operation op, t_state *state);

/* stack operations */
void	swap(t_list **lst);
void	push(t_list **lst, int *n);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);

/* stacker utils */
t_list	*stack_create(int *nums, int len);
t_list	*stack_pop(t_list **lst);
t_list	*stack_shift(t_list **lst);
void	stack_push(t_list **lst, t_list *new);

#endif
