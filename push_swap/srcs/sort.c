/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:45:42 by brunogue          #+#    #+#             */
/*   Updated: 2025/03/30 17:31:15 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**ft_sort_a(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*temp;

	while (*b)
	{
		temp = *b;
		i = ft_rotate_type_ba(*a, *b);
		while (i >= 0)
		{
			if (i == ft_rarb_a(*a, *b, temp->nbr))
				i = ft_apply_rarb(a, b, temp->nbr, 'b');
			else if (i == ft_rarrb_a(*a, *b, temp->nbr))
				i = ft_apply_rarrb(a, b, temp->nbr, 'b');
			else if (i == ft_rrarrb_a(*a, *b, temp->nbr))
				i = ft_apply_rrarrb(a, b, temp->nbr, 'b');
			else if (i == ft_rrarb_a(*a, *b, temp->nbr))
				i = ft_apply_rrarb(a, b, temp->nbr, 'b');
			else
				temp = temp->next;
		}
	}
	return (a);
}

t_stack	*ft_sort_b(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_stack_size(*a) > 3 && !ft_checksorted(*a))
		ft_pb(a, &b, 0);
	if (ft_stack_size(*a) > 3 && !ft_checksorted(*a))
		ft_pb(a, &b, 0);
	if (ft_stack_size(*a) > 3 && !ft_checksorted(*a))
		ft_sort_b_3(a, &b);
	if (!ft_checksorted(*a))
		ft_sort_three(a);
	return (b);
}

void	ft_sort(t_stack **a)
{
	t_stack	*b;
	int		i;

	b = NULL;
	if (ft_stack_size(*a) == 2)
		ft_sa(a, 0);
	else
	{
		b = ft_sort_b(a);
		a = ft_sort_a(a, &b);
		i = ft_find_index(*a, ft_min_number(*a));
		if (i < ft_stack_size(*a) - i)
		{
			while ((*a)->nbr != ft_min_number(*a))
				ft_ra(a, 0);
		}
		else
		{
			while ((*a)->nbr != ft_min_number(*a))
				ft_rra(a, 0);
		}
	}
}

void	ft_sort_b_3(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	while (ft_stack_size(*a) > 3 && !ft_checksorted(*a))
	{
		tmp = *a;
		i = ft_rotate_type_ab(*a, *b);
		while (i >= 0)
		{
			if (i == ft_rarb(*a, *b, tmp->nbr))
				i = ft_apply_rarb(a, b, tmp->nbr, 'a');
			else if (i == ft_rrarrb(*a, *b, tmp->nbr))
				i = ft_apply_rrarrb(a, b, tmp->nbr, 'a');
			else if (i == ft_rarrb(*a, *b, tmp->nbr))
				i = ft_apply_rarrb(a, b, tmp->nbr, 'a');
			else if (i == ft_rrarb(*a, *b, tmp->nbr))
				i = ft_apply_rrarb(a, b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

void	ft_sort_three(t_stack **a)
{
	if (ft_min_number(*a) == (*a)->nbr)
	{
		ft_rra(a, 0);
		ft_sa(a, 0);
	}
	else if (ft_max_number(*a) == (*a)->nbr)
	{
		ft_ra(a, 0);
		if (!ft_checksorted(*a))
			ft_sa(a, 0);
	}
	else
	{
		if (ft_find_index(*a, ft_max_number(*a)) == 1)
			ft_rra(a, 0);
		else
			ft_sa(a, 0);
	}
}
