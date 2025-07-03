/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:08:59 by brunogue          #+#    #+#             */
/*   Updated: 2025/03/12 15:55:36 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

//SERVER
void	clean_exit(int signum);
void	ft_receive(int signal, siginfo_t *info, void *context);
void	add_char_to_message(char c, char **message);
char	*append_char(char *msg, char c);
//UTILS
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_atoi(char *str);

#endif