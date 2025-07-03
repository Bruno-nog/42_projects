/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_positioning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:45:44 by brunogue          #+#    #+#             */
/*   Updated: 2025/03/30 18:56:47 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_stack_last(*stack))->next = stack_new;
}

int	ft_find_index(t_stack *a, int nbr)
{
	int	i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	ft_find_node_a(t_stack *a, int push_number)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (push_number < a->nbr && push_number > ft_stack_last(a)->nbr)
		i = 0;
	else if (push_number > ft_max_number(a) || push_number < ft_min_number(a))
		i = ft_find_index(a, ft_min_number(a));
	else
	{
		temp = a->next;
		while (a->nbr > push_number || temp->nbr < push_number)
		{
			a = a->next;
			temp = a->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_node_b(t_stack *b, int push_number)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (push_number > b->nbr && push_number < ft_stack_last(b)->nbr)
		i = 0;
	else if (push_number > ft_max_number(b) || push_number < ft_min_number(b))
		i = ft_find_index(b, ft_max_number(b));
	else
	{
		temp = b->next;
		while (b->nbr < push_number || temp->nbr > push_number)
		{
			b = b->next;
			temp = b->next;
			i++;
		}
	}
	return (i);
}
