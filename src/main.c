/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2021/05/28 19:32:56 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	bones_loading(t_context *context)
{
	context->ticks = 0;
	SDLX_RenderQueue_init(&(context->rQueue));

	SDLX_new_Sprite(&(context->start_sprite));
	fetch_ui_sprite(&(context->start_sprite.sprite_data), START_NORM);
	context->start_sprite._dst = (SDL_Rect){50, 20, 32, 16};

	SDLX_init_button(&(context->exit_button),
			fetch_ui_sprite, EXIT_NORM, (SDL_Rect){70, 36, 32, 16},
			&(context->rQueue));
	SDLX_style_button(&(context->exit_button), EXIT_NORM, EXIT_HOVER);

	g_GameInput.key_mapper.map_arr = menu_key_map(&(g_GameInput.key_mapper.amount));
}

int	main(void)
{
	t_context	context;
	SDL_bool	window_exit;
	int			ticks;
	SDL_Point	mouse;
	const Uint8	*keystate;

	bones_loading(&(context));
	context.exit_button.mouse = &(mouse);

	window_exit = SDL_FALSE;
	while (window_exit == SDL_FALSE)
	{
		window_exit = SDLX_poll();

		keystate = SDL_GetKeyboardState(NULL);
		SDLX_KeyMap(&(g_GameInput.key_mapper), keystate);

		SDL_GetMouseState(&(mouse.x), &(mouse.y));
		SDLX_Mouse_to_Screen(&(mouse.x), &(mouse.y));

		SDLX_update_button(&(context.exit_button));

		context.start_sprite.current++;
		context.exit_sprite.current++;

		if (window_exit != SDL_TRUE && SDLX_discrete_frames(&(ticks)) != EXIT_FAILURE)
		{
			SDLX_RenderQueue_flush(&(context.rQueue), SDLX_GetDisplay()->renderer);
			SDLX_screen_reset(SDLX_GetDisplay()->renderer, NULL);
		}
	}

	return (EXIT_SUCCESS);
}
