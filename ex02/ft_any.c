/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 20:30:10 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/02 02:32:42 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @fn int ft_any(char **tab, int (*f)(char*))
 * @brief Evaluates if at least one string in an array satisfies a condition.
 * @details Iterates through a null-terminated array of strings. If the
 * provided evaluation function returns non-zero for any string, it returns 1.
 * @param tab A null-terminated array of string pointers.
 * @param f A pointer to the conditional evaluation function.
 * @return 1 if at least one element satisfies the condition, 0 otherwise.
 */
int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	if (!tab || !f)
		return (0);
	i = -1;
	while (tab[++i])
		if (f(tab[i]) != 0)
			return (1);
	return (0);
}
