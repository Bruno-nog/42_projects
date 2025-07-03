/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:08:23 by brunogue          #+#    #+#             */
/*   Updated: 2025/03/12 15:54:58 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(pid_t server_pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_printf("Error sending SIGUSR2");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_printf("Error sending SIGUSR1");
				exit(EXIT_FAILURE);
			}
		}
		usleep(100);
		bit--;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*message;

	if (ac != 3)
	{
		write(2, "Usage: ./client <server PID> <message>\n", 40);
		return (1);
	}
	server_pid = (pid_t)ft_atoi(av[1]);
	if (server_pid <= 0)
	{
		write(2, "Invalid PID\n", 12);
		return (1);
	}
	message = av[2];
	while (*message)
	{
		send_char(server_pid, *message);
		message++;
	}
	send_char(server_pid, '\0');
	return (0);
}
