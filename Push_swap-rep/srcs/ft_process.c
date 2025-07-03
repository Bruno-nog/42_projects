/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:45:09 by brunogue          #+#    #+#             */
/*   Updated: 2025/04/02 17:56:21 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_subprocess(char **av)
{
	t_stack	*a;
	char	**temp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	temp = ft_split(av[1], 32);
	while (temp[i])
	{
		j = ft_atoi2(temp[i]);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_free_str(temp);
	free(temp);
	return (a);
}

t_stack	*ft_process(int ac, char **av)
{
	t_stack	*a;
	int		i;
	int		x;

	i = 1;
	a = NULL;
	if (ac < 2)
		ft_error_arg();
	if (ac == 2)
		a = ft_subprocess(av);
	else
	{
		while (i < ac)
		{
			x = ft_atoi2(av[i]);
			ft_add_back(&a, ft_stack_new(x));
			i++;
		}
	}
	return (a);
}
