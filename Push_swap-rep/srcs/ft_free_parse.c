/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:44:58 by brunogue          #+#    #+#             */
/*   Updated: 2025/04/02 17:56:15 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = temp;
	}
}

void	ft_free_str(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}

void	ft_list_args(char **av, t_stack **a)
{
	long	i;

	i = 1;
	while (av[i] != NULL)
	{
		ft_add_back(a, ft_stack_new(ft_atoi(av[i])));
		i++;
	}
}

t_stack	*ft_parse_args_quoted(char **av)
{
	t_stack		*a;
	char		**temp;

	a = NULL;
	temp = ft_split(av[1], ' ');
	ft_list_args(temp, &a);
	ft_free_str(temp);
	free(temp);
	return (a);
}

t_stack	*ft_parse(int ac, char **av)
{
	t_stack	*a;

	a = NULL;
	if (ac < 2)
		ft_error_arg();
	else if (ac == 2)
		a = ft_parse_args_quoted(av);
	else
		ft_list_args(av, &a);
	return (a);
}
