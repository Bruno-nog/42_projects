/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:52:20 by brunogue          #+#    #+#             */
/*   Updated: 2025/03/30 19:14:16 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **a, int i)
{
	t_stack	*last;
	int		x;

	if (!*a || !(*a)->next)
		return ;
	x = 0;
	last = *a;
	while ((*a)->next != NULL)
	{
		*a = (*a)->next;
		x++;
	}
	(*a)->next = last;
	while (x > 1)
	{
		last = last->next;
		x--;
	}
	last->next = NULL;
	if (i == 0)
		write (1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int i)
{
	t_stack	*last;
	int		x;

	if (!*b || !(*b)->next)
		return ;
	x = 0;
	last = *b;
	while ((*b)->next != NULL)
	{
		x++;
		*b = (*b)->next;
	}
	(*b)->next = last;
	while (x > 1)
	{
		last = last->next;
		x--;
	}
	last->next = NULL;
	if (i == 0)
		write (1, "rra\n", 4);
}

void	ft_rrr_cont(t_stack **b, int i)
{
	t_stack	*temp;
	int		x;

	x = 0;
	temp = *b;
	while ((*b)->next)
	{
		x++;
		*b = (*b)->next;
	}
	(*b)->next = temp;
	while (x > 1)
	{
		temp = temp->next;
		x--;
	}
	temp->next = NULL;
	if (i == 0)
		write(1, "rrr\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int i)
{
	t_stack	*temp;
	int		x;

	temp = *a;
	x = 0;
	while ((*a)->next)
	{
		x++;
		*a = (*a)->next;
	}
	(*a)->next = temp;
	while (x > 1)
	{
		temp = temp->next;
		x--;
	}
	temp->next = NULL;
	ft_rrr_cont(b, i);
}
