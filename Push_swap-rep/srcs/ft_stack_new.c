/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:45:22 by brunogue          #+#    #+#             */
/*   Updated: 2025/03/30 18:55:13 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		ft_error_memory();
	new->nbr = content;
	new->next = NULL;
	return (new);
}
