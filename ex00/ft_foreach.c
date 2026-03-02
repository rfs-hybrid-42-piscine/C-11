/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:46:25 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/02 02:25:17 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @fn void ft_foreach(int *tab, int length, void (*f)(int))
 * @brief Applies a function to all elements of an integer array.
 * @details Iterates through the array sequentially and passes each element
 * to the provided function pointer. Safeguards against NULL arrays or functions.
 * @param tab The integer array to iterate over.
 * @param length The total number of elements in the array.
 * @param f A pointer to the function to apply to each element.
 */
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	if (!tab || !f)
		return ;
	i = -1;
	while (++i < length)
		f(tab[i]);
}
