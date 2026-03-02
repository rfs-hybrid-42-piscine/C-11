/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:53:30 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/02 02:25:35 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @fn int *ft_map(int *tab, int length, int (*f)(int))
 * @brief Transforms an array by applying a function to each element.
 * @details Allocates a new integer array dynamically and populates it with
 * the return values of the provided function evaluated on the original array.
 * @param tab The original integer array.
 * @param length The total number of elements in the array.
 * @param f A pointer to the transformation function.
 * @return A dynamically allocated array containing the transformed values,
 * or NULL on allocation failure or invalid inputs.
 */
int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new;
	int	i;

	if (!tab || !f)
		return (NULL);
	new = malloc(sizeof(int) * length);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < length)
		new[i] = f(tab[i]);
	return (new);
}
