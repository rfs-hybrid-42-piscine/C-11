/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 22:07:09 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/02 02:46:09 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @fn int ft_add(int a, int b)
 * @brief Performs addition.
 * @details Adds the two integer parameters together.
 * @param a The first operand.
 * @param b The second operand.
 * @return The sum of a and b.
 */
int	ft_add(int a, int b)
{
	return (a + b);
}

/**
 * @fn int ft_sub(int a, int b)
 * @brief Performs subtraction.
 * @details Subtracts the second integer parameter from the first.
 * @param a The base operand.
 * @param b The operand to subtract.
 * @return The difference of a and b.
 */
int	ft_sub(int a, int b)
{
	return (a - b);
}

/**
 * @fn int ft_mul(int a, int b)
 * @brief Performs multiplication.
 * @details Multiplies the two integer parameters.
 * @param a The first operand.
 * @param b The second operand.
 * @return The product of a and b.
 */
int	ft_mul(int a, int b)
{
	return (a * b);
}

/**
 * @fn int ft_div(int a, int b)
 * @brief Performs integer division.
 * @details Divides the first parameter by the second. Handled safely by
 * the caller to prevent division by zero.
 * @param a The dividend.
 * @param b The divisor.
 * @return The quotient of a and b.
 */
int	ft_div(int a, int b)
{
	return (a / b);
}

/**
 * @fn int ft_mod(int a, int b)
 * @brief Performs the modulo operation.
 * @details Calculates the remainder of the division between the two parameters.
 * @param a The dividend.
 * @param b The divisor.
 * @return The remainder of a divided by b.
 */
int	ft_mod(int a, int b)
{
	return (a % b);
}
