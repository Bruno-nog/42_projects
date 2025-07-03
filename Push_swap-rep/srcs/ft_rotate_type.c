/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:45:25 by brunogue          #+#    #+#             */
/*   Updated: 2025/03/30 18:54:59 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = b;
	i = ft_rrarrb_a(a, b, b->nbr);
	while (temp)
	{
		if (i > ft_rarb_a(a, b, temp->nbr))
			i = ft_rarb_a(a, b, temp->nbr);
		if (i > ft_rrarrb_a(a, b, temp->nbr))
			i = ft_rrarrb_a(a, b, temp->nbr);
		if (i > ft_rarrb_a(a, b, temp->nbr))
			i = ft_rarrb_a(a, b, temp->nbr);
		if (i > ft_rrarb_a(a, b, temp->nbr))
			i = ft_rrarb_a(a, b, temp->nbr);
		temp = temp->next;
	}
	return (i);
}

int	ft_rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = a;
	i = ft_rrarrb(a, b, a->nbr);
	while (temp)
	{
		if (i > ft_rarb(a, b, temp->nbr))
			i = ft_rarb(a, b, temp->nbr);
		if (i > ft_rrarrb(a, b, temp->nbr))
			i = ft_rrarrb(a, b, temp->nbr);
		if (i > ft_rarrb(a, b, temp->nbr))
			i = ft_rarrb(a, b, temp->nbr);
		if (i > ft_rrarb(a, b, temp->nbr))
			i = ft_rrarb(a, b, temp->nbr);
		temp = temp->next;
	}
	return (i);
}
