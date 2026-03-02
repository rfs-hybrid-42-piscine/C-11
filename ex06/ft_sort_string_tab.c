/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 01:59:36 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/02 02:46:52 by maaugust         ###   ########.fr       */
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
 * @fn static int ft_strcmp(char *s1, char *s2)
 * @brief Compares two strings in ASCII order.
 * @details Evaluates characters sequentially until a difference is found or
 * the end of a string is reached.
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return >0 if s1 is greater, <0 if s2 is greater, 0 if equal.
 */
static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
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
 * @fn void ft_sort_string_tab(char **tab)
 * @brief Sorts an array of strings in ascending ASCII order.
 * @details Employs a Bubble Sort algorithm, optimizing execution by swapping
 * the memory addresses of the string pointers utilizing ft_strcmp.
 * @param tab The null-terminated string array to be sorted.
 */
void	ft_sort_string_tab(char **tab)
{
	int	size;
	int	i;
	int	j;

	if (!tab)
		return ;
	size = tab_size(tab);
	if (size < 2)
		return ;
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
	}
}
