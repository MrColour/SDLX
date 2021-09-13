/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2021/09/13 01:32:56 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	SDL_bool	window_exit;
	int			ticks;

	window_exit = SDL_FALSE;
	while (window_exit == SDL_FALSE)
	{
		window_exit = SDLX_poll();

		if (window_exit != SDL_TRUE && SDLX_discrete_frames(&(ticks)) != EXIT_FAILURE)
			SDLX_ScreenReset(SDLX_GetDisplay()->renderer, NULL);
	}

	return (EXIT_SUCCESS);
}
