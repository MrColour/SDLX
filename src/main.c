/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2021/05/21 00:54:24 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

int	main(void)
{
	SDL_bool	window_exit;
	int			ticks;

	window_exit = SDL_FALSE;
	while (window_exit == SDL_FALSE)
	{
		window_exit = SDLX_poll();

		if (window_exit != SDL_TRUE && SDLX_discrete_frames(&(ticks)) != EXIT_FAILURE)
		{
			SDLX_RenderQueue_flush(NULL, SDLX_GetDisplay()->renderer);
			SDLX_screen_reset(SDLX_GetDisplay()->renderer, NULL);
		}
	}

	return (EXIT_SUCCESS);
}
