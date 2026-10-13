/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:53:25 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/13 13:48:03 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyzer.h"

/* Count total inversions found in array */
static long	count_inversions(const int *nums, int size)
{
	long	inv;
	int		i;
	int		j;

	inv = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] > nums[j])
				inv++;
			j++;
		}
		i++;
	}
	return (inv);
}

/* Calculates disorder scaled ratio (base 10000) */
int	get_disorder(const int *numbers, int size)
{
	long	total_pairs;
	long	inv;
	long	scaled;

	if (!numbers || size <= 1)
		return (0);
	total_pairs = ((long)size * (size - 1)) / 2;
	inv = count_inversions(numbers, size);
	scaled = ((inv * 10000) + (total_pairs / 2)) / total_pairs;
	return ((int)scaled);
}
