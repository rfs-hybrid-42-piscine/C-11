/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:12:39 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/02 02:33:02 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @fn int ft_count_if(char **tab, int length, int (*f)(char*))
 * @brief Counts the number of strings that satisfy a specific condition.
 * @details Increments a counter each time the provided evaluation function
 * returns a non-zero value for an element in the array.
 * @param tab The array of string pointers.
 * @param length The maximum number of elements to process.
 * @param f A pointer to the conditional evaluation function.
 * @return The total number of elements that met the condition.
 */
int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	cnt;
	int	i;

	cnt = 0;
	if (!tab || !f)
		return (cnt);
	i = -1;
	while (++i < length && tab[i])
		if (f(tab[i]) != 0)
			cnt++;
	return (cnt);
}
