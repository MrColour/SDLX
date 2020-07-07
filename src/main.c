/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2020/07/06 20:04:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	game_context_initialize(t_game_context *game_state, t_display *display)
{
	game_state->active = true;

	// game_state->texture = IMG_LoadTexture(display->renderer, "");
	// game_state->src_rect = carve__texture();

	game_state->ticks = 0;
	game_state->game_over = false;

	// srand(time(NULL));
	(void)display;
}

int	main(void)
{
	t_display		display;
	t_game_context	game_state;

	SDLU_start(&display);
	game_context_initialize(&game_state, &display);
	while (game_state.active == true)
	{
		process_user_input(&game_state);

		update_game_state(&game_state);

		SDL_RenderPresent(display.renderer);
		SDL_RenderClear(display.renderer);

	}
	SDLU_close(&display);
	return (0);
}
