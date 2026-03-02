/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 02:58:22 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/02 02:59:05 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Master Switch --- */
#ifdef TEST_ALL
# define EX00
# define EX01
# define EX02
# define EX03
# define EX04
/* ex05 is a standalone program (do-op) and is manually tested */
# define EX06
# define EX07
#endif

/* --- Prototypes --- */
void	ft_foreach(int *tab, int length, void (*f)(int));
int		*ft_map(int *tab, int length, int (*f)(int));
int		ft_any(char **tab, int (*f)(char*));
int		ft_count_if(char **tab, int length, int (*f)(char*));
int		ft_is_sort(int *tab, int length, int (*f)(int, int));
void	ft_sort_string_tab(char **tab);
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));

/* --- Helper Functions for Pointers --- */
void	print_int(int n)
{
	printf("%d ", n);
}

int		multiply_by_two(int n)
{
	return (n * 2);
}

int		starts_with_upper(char *str)
{
	if (str && str[0] >= 'A' && str[0] <= 'Z')
		return (1);
	return (0);
}

int		cmp_int(int a, int b)
{
	return (a - b);
}

int		rev_strcmp(char *s1, char *s2)
{
	return (strcmp(s2, s1));
}

/* --- Main Testing Function --- */
int	main(void)
{
#ifdef EX00
	printf("--- EX00: ft_foreach ---\n");
	int tab0[] = {1, 2, 3, 4, 5};
	printf("Expected: 1 2 3 4 5 \nResult  : ");
	ft_foreach(tab0, 5, &print_int);
	printf("\n\n");
#endif

#ifdef EX01
	printf("--- EX01: ft_map ---\n");
	int tab1[] = {1, 2, 3, 4, 5};
	int *res1 = ft_map(tab1, 5, &multiply_by_two);
	printf("Expected: 2 4 6 8 10 \nResult  : ");
	if (res1)
	{
		for (int i = 0; i < 5; i++)
			printf("%d ", res1[i]);
		free(res1);
	}
	printf("\n\n");
#endif

#ifdef EX02
	printf("--- EX02: ft_any ---\n");
	char *tab2_true[] = {"hello", "World", "test", NULL};
	char *tab2_false[] = {"hello", "world", "test", NULL};
	printf("Has Uppercase (True array) : %d (Expected: 1)\n", ft_any(tab2_true, &starts_with_upper));
	printf("Has Uppercase (False array): %d (Expected: 0)\n\n", ft_any(tab2_false, &starts_with_upper));
#endif

#ifdef EX03
	printf("--- EX03: ft_count_if ---\n");
	char *tab3[] = {"Hello", "World", "test", "Apple", NULL};
	printf("Uppercase count: %d (Expected: 3)\n\n", ft_count_if(tab3, 4, &starts_with_upper));
#endif

#ifdef EX04
	printf("--- EX04: ft_is_sort ---\n");
	int tab4_asc[] = {1, 2, 3, 4, 5};
	int tab4_desc[] = {5, 4, 3, 2, 1};
	int tab4_rand[] = {1, 3, 2, 5, 4};
	int tab4_same[] = {2, 2, 2, 2, 2};
	printf("Ascending array : %d (Expected: 1)\n", ft_is_sort(tab4_asc, 5, &cmp_int));
	printf("Descending array: %d (Expected: 1)\n", ft_is_sort(tab4_desc, 5, &cmp_int));
	printf("All same array  : %d (Expected: 1)\n", ft_is_sort(tab4_same, 5, &cmp_int));
	printf("Random array    : %d (Expected: 0)\n\n", ft_is_sort(tab4_rand, 5, &cmp_int));
#endif

#ifdef EX06
	printf("--- EX06: ft_sort_string_tab ---\n");
	char *tab6[] = {"Zebra", "Apple", "Mango", "Banana", NULL};
	ft_sort_string_tab(tab6);
	printf("Expected: Apple Banana Mango Zebra \nResult  : ");
	for (int i = 0; tab6[i] != NULL; i++)
		printf("%s ", tab6[i]);
	printf("\n\n");
#endif

#ifdef EX07
	printf("--- EX07: ft_advanced_sort_string_tab ---\n");
	char *tab7[] = {"Apple", "Zebra", "Mango", "Banana", NULL};
	/* Sorting in reverse using the custom rev_strcmp helper */
	ft_advanced_sort_string_tab(tab7, &rev_strcmp);
	printf("Expected (Reverse): Zebra Mango Banana Apple \nResult            : ");
	for (int i = 0; tab7[i] != NULL; i++)
		printf("%s ", tab7[i]);
	printf("\n\n");
#endif

	return (0);
}
