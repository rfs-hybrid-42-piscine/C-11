/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:19:31 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/02 02:33:18 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @fn int ft_is_sort(int *tab, int length, int (*f)(int, int))
 * @brief Checks if an integer array is completely sorted.
 * @details Determines the initial sorting direction (ascending or descending)
 * and iterates to ensure no subsequent elements break that sequence rule.
 * @param tab The integer array to validate.
 * @param length The number of elements in the array.
 * @param f A comparison function returning <0, 0, or >0.
 * @return 1 if the array is sorted, 0 if the sequence is broken.
 */
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	cmp_res;
	int	sort_dir;
	int	i;

	if (!f)
		return (0);
	sort_dir = 0;
	i = -1;
	while (++i < length - 1)
	{
		cmp_res = f(tab[i], tab[i + 1]);
		if (sort_dir == 0)
			sort_dir = (cmp_res < 0) - (cmp_res > 0);
		if ((cmp_res < 0 && sort_dir == -1) || (cmp_res > 0 && sort_dir == 1))
			return (0);
	}
	return (1);
}
