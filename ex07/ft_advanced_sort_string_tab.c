/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 02:18:25 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/02 02:47:24 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @fn static void ft_swap(char **s1, char **s2)
 * @brief Swaps two string pointers in memory.
 * @details Modifies the double pointers to swap the addresses of the strings
 * without moving actual character data, optimizing the sort.
 * @param s1 A pointer to the first string pointer.
 * @param s2 A pointer to the second string pointer.
 */
static void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

/**
 * @fn static int tab_size(char **tab)
 * @brief Calculates the number of elements in a null-terminated array.
 * @details Iterates through the array of pointers until a NULL is encountered.
 * @param tab The string array to measure.
 * @return The integer count of valid string elements.
 */
static int	tab_size(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

/**
 * @fn void ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
 * @brief Sorts an array of strings based on a custom comparison function.
 * @details Executes a Bubble Sort utilizing the user-provided function pointer
 * to dynamically evaluate whether the adjacent elements should be swapped.
 * @param tab The null-terminated string array to be sorted.
 * @param cmp A pointer to the custom comparison function.
 */
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	size;
	int	i;
	int	j;

	if (!tab || !cmp)
		return ;
	size = tab_size(tab);
	if (size < 2)
		return ;
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
	}
}
