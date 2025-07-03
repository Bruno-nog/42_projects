/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:53:10 by brunogue          #+#    #+#             */
/*   Updated: 2025/03/30 19:13:54 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int i)
{
	t_stack	*temp;
	t_stack	*next_temp;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	next_temp = (*a)->next;
	*a = next_temp;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (i == 0)
		write (1, "sa\n", 3);
}

void	ft_sb(t_stack **b, int i)
{
	t_stack	*temp;

	if (!*b || !((*b)->next))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	if (i == 0)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b, int i)
{
	t_stack	*temp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	if (i == 0)
		write(1, "ss\n", 3);
}
