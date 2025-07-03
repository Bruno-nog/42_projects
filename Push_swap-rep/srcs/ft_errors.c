/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:44:51 by brunogue          #+#    #+#             */
/*   Updated: 2025/04/02 15:43:22 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_digit(void)
{
	write(2, "Must be digits\n", 15);
	exit(1);
}

void	ft_error_limit_numbers(void)
{
	write (2, "Limit of numbers reached\n", 26);
	exit(1);
}

void	ft_error_arg(void)
{
	write (2, "Error of usage: ./exec [numbers]\n", 33);
	exit(1);
}

void	ft_error_stack_dup(void)
{
	write (2, "Duplicate stack or something failed in a stack\n", 33);
	exit(1);
}

void	ft_error_memory(void)
{
	write (2, "Memory usage error\n", 19);
	exit(1);
}
