/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:51:52 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/02 02:42:17 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_add(int a, int b);
int	ft_sub(int a, int b);
int	ft_mul(int a, int b);
int	ft_div(int a, int b);
int	ft_mod(int a, int b);

/**
 * @fn static void ft_putnbr(int nb)
 * @brief Prints an integer to standard output.
 * @details Handles negative numbers gracefully and recursively prints digits
 * using the write system call to avoid external libraries.
 * @param nb The integer to be printed.
 */
static void	ft_putnbr(int nb)
{
	unsigned int	n;
	char			c;

	if (nb < 0)
	{
		write(1, "-", 1);
		n = (unsigned int)(-nb);
	}
	else
		n = (unsigned int)nb;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

/**
 * @fn static int ft_atoi(char *str)
 * @brief Converts a string to an integer.
 * @details Parses leading whitespace, handles optional signs, and accumulates
 * numeric characters to return the integer value dynamically.
 * @param str The string to parse.
 * @return The converted integer value.
 */
static int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

/**
 * @fn static void load_operations(int (*calc[5])(int, int))
 * @brief Populates the mathematical dispatch table.
 * @details Assigns the calculator function pointers to their respective
 * indices in the array to enable dynamic routing based on the operator.
 * @param calc The array of function pointers to be populated.
 */
static void	load_operations(int (*calc[5])(int, int))
{
	calc[0] = ft_add;
	calc[1] = ft_sub;
	calc[2] = ft_mul;
	calc[3] = ft_div;
	calc[4] = ft_mod;
}

/**
 * @fn static void do_op(int n1, char op, int n2)
 * @brief Executes the requested mathematical operation dynamically.
 * @details Iterates through the supported operators array. If a match is found,
 * it calls the corresponding function pointer. Handles division/modulo by zero.
 * @param n1 The first operand.
 * @param op The character representing the mathematical operator.
 * @param n2 The second operand.
 */
static void	do_op(int n1, char op, int n2)
{
	char	*type;
	int		(*calc[5])(int, int);
	int		i;

	type = "+-*/%";
	load_operations(calc);
	i = -1;
	while (++i < 5)
	{
		if (op == type[i])
		{
			if (n2 == 0 && i == 3)
				write(1, "Stop: division by zero\n", 23);
			else if (n2 == 0 && i == 4)
				write(1, "Stop modulo by zero\n", 20);
			else
			{
				ft_putnbr(calc[i](n1, n2));
				write(1, "\n", 1);
			}
			return ;
		}
	}
	write(1, "0\n", 2);
}

/**
 * @fn int main(int argc, char **argv)
 * @brief Entry point for the do-op program.
 * @details Validates the argument count and strictly checks the operator string
 * length to reject chained invalid operators (like "+-") before executing.
 * @param argc The argument count.
 * @param argv The argument vector array.
 * @return 0 on successful execution.
 */
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][1] != '\0')
			write(1, "0\n", 2);
		else
			do_op(ft_atoi(argv[1]), *argv[2], ft_atoi(argv[3]));
	}
	return (0);
}
