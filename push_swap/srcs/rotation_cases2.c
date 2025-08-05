/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_cases2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:45:37 by brunogue          #+#    #+#             */
/*   Updated: 2025/03/30 18:55:56 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_node_a(a, c);
	if (i < ft_find_index(b, c))
		i = ft_find_index(b, c);
	return (i);
}

int	ft_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_node_a(a, c))
		i = ft_stack_size(a) - ft_find_node_a(a, c);
	if ((i < (ft_stack_size(b) - ft_find_index(b, c))) && ft_find_index(b, c))
		i = ft_stack_size(b) - ft_find_index(b, c);
	return (i);
}

int	ft_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(b, c))
		i = ft_stack_size(b) - ft_find_index(b, c);
	i = ft_find_node_a(a, c) + i;
	return (i);
}

int	ft_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_node_a(a, c))
		i = ft_stack_size(a) - ft_find_node_a(a, c);
	i = ft_find_index(b, c) + i;
	return (i);
}
