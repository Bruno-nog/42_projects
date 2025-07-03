/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:42:29 by brunogue          #+#    #+#             */
/*   Updated: 2025/04/02 17:30:50 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkdup(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->nbr == temp->nbr)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

int	ft_checksorted(t_stack *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (i > a->nbr)
			return (0);
		i = a->nbr;
		a = a->next;
	}
	return (1);
}

void	checkalpha(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while ((av[i][j]) != '\0')
		{
			if (ft_isalpha(av[i][j]))
				ft_error_digit();
			j++;
		}
	}
}

int	checkargs(char **av)
{
	checkalpha(av);
	if (!checkargs_syntax(av, 1, 0))
		return (0);
	return (1);
}

int	checkargs_syntax(char **av, int i, int x)
{
	while (av[i])
	{
		x = 0;
		while (av[i][x] != '\0')
		{
			if (sign(av[i][x]))
			{
				x++;
				if (!digit(av[i][x]))
					return (0);
			}
			else if (digit(av[i][x]))
			{
				x++;
				if (av[i][x] == '\0')
					break ;
				if (!digit(av[i][x]) && !space(av[i][x]))
					return (0);
			}
			x++;
		}
		i++;
	}
	return (1);
}
