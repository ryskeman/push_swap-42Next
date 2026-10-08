/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 17:02:28 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/08 09:18:50 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKER_H
# define STACKER_H

# include <stdlib.h>
# include "../libft/libft.h"

t_list	*stack_create(int *nums, int len);
void	swap(t_list **lst);
void	push(t_list **lst, int *n);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);

#endif
