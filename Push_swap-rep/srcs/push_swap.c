/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:45:35 by brunogue          #+#    #+#             */
/*   Updated: 2025/04/02 17:29:30 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;

	a = ft_process(ac, av);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error_stack_dup();
	}
	if (!ft_checksorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
