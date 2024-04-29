/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:27:10 by tohma             #+#    #+#             */
/*   Updated: 2024/04/29 16:32:08 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	setup_signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = sig_on_interrupt;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}

void	sig_on_interrupt(int code)
{
	(void)code;
	/*
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();*/
}
