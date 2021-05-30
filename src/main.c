/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2021/05/29 22:14:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*button_trigger(SDLX_button *self, SDL_UNUSED void *meta, SDL_UNUSED size_t meta_length)
{
	if (g_GameInput.GameInput.button_A == 1 && self->triggered == SDL_FALSE)
	{
		SDL_Log("Button pressed");
		self->triggered = SDL_TRUE;
	}
	return (NULL);
}

void	*button_update(SDLX_button *self, SDL_UNUSED void *meta, SDL_UNUSED size_t meta_length)
{
	SDLX_button	*to;

	to = NULL;
	if (g_GameInput.GameInput.button_A == 0)
		self->triggered = SDL_FALSE;

	if (g_GameInput.GameInput.button_DPAD_UP == 1 && g_GameInput_prev.GameInput.button_DPAD_UP == 0 && self->focused)
	{
		to = self->up;
		self->focused = SDL_FALSE;
		g_GameInput_prev.GameInput.button_DPAD_UP = 1;
		self->sprite_fn(&(self->sprite.sprite_data), self->norm_no);
	}

	if (g_GameInput.GameInput.button_DPAD_DOWN == 1 && g_GameInput_prev.GameInput.button_DPAD_DOWN == 0 && self->focused)
	{
		to = self->down;
		self->focused = SDL_FALSE;
		g_GameInput_prev.GameInput.button_DPAD_DOWN = 1;
		self->sprite_fn(&(self->sprite.sprite_data), self->norm_no);
	}

	if (to != NULL)
	{
		to->sprite_fn(&(to->sprite.sprite_data), to->focus_no);
		to->focused = SDL_TRUE;
	}
	return (NULL);
}

void	bones_loading(t_context *context)
{
	context->ticks = 0;
	SDLX_RenderQueue_init(&(context->rQueue));

	SDLX_init_button(&(context->start_button), fetch_ui_sprite, START_NORM, (SDL_Rect){50, 10, 32, 16}, &(context->rQueue));
	SDLX_init_button(&(context->sound_button), fetch_ui_sprite, SOUND_NORM, (SDL_Rect){50, 26, 32, 16}, &(context->rQueue));
	SDLX_init_button(&(context->exit_button), fetch_ui_sprite, EXIT_NORM, (SDL_Rect){50, 42, 32, 16}, &(context->rQueue));

	SDLX_style_button(&(context->start_button), START_NORM, START_HOVER);
	SDLX_style_button(&(context->sound_button), SOUND_NORM, SOUND_HOVER);
	SDLX_style_button(&(context->exit_button), EXIT_NORM, EXIT_HOVER);
	SDLX_Button_set_fn(&(context->start_button), SDLX_Button_onHoverFocus, SDLX_button_null_fn, SDLX_button_null_fn, button_trigger, button_update);
	SDLX_Button_set_fn(&(context->sound_button), SDLX_Button_onHoverFocus, SDLX_button_null_fn, SDLX_button_null_fn, button_trigger, button_update);
	SDLX_Button_set_fn(&(context->exit_button), SDLX_Button_onHoverFocus, SDLX_button_null_fn, SDLX_button_null_fn, button_trigger, button_update);

	context->start_button.up = &(context->exit_button);
	context->start_button.down = &(context->sound_button);

	context->sound_button.up = &(context->start_button);
	context->sound_button.down = &(context->exit_button);

	context->exit_button.up = &(context->sound_button);
	context->exit_button.down = &(context->start_button);

	context->start_button.meta = &(g_GameInput);
	context->sound_button.meta = &(g_GameInput);
	context->exit_button.meta = &(g_GameInput);

	context->start_button.meta_length = 1;
	context->sound_button.meta_length = 1;
	context->exit_button.meta_length = 1;

	g_GameInput.key_mapper.map_arr = menu_key_map(&(g_GameInput.key_mapper.amount));

	SDLX_new_Sprite(&(context->background));
	context->background.sprite_data = SDL_calloc(1, sizeof(*context->background.sprite_data));
	context->background.sprite_data[0].texture = IMG_LoadTexture(SDLX_GetDisplay()->renderer, ASSETS"background.png");
	context->background.sprite_data[0].src = NULL;
	context->background.sprite_data[0].cycle = 1;
	context->background.dst = NULL;
	SDLX_set_background(&(context->background));
}

int	main(void)
{
	t_context	context;
	SDL_bool	window_exit;
	int			ticks;
	const Uint8	*keystate;

	bones_loading(&(context));

	window_exit = SDL_FALSE;
	while (window_exit == SDL_FALSE)
	{
		window_exit = SDLX_poll();

		keystate = SDL_GetKeyboardState(NULL);
		SDLX_KeyMap(&(g_GameInput.key_mapper), keystate);
		SDLX_GameInput_Mouse_Fill(&(g_GameInput), SDL_TRUE);

		SDLX_update_button(&(context.start_button));
		SDLX_update_button(&(context.sound_button));
		SDLX_update_button(&(context.exit_button));

		SDLX_record_input(&(g_GameInput));

		if (window_exit != SDL_TRUE && SDLX_discrete_frames(&(ticks)) != EXIT_FAILURE)
		{
			SDLX_RenderQueue_flush(&(context.rQueue), SDLX_GetDisplay()->renderer);
			SDLX_screen_reset(SDLX_GetDisplay()->renderer, NULL);
			g_GameInput.GameInput.button_A = 0;
		}
	}

	return (EXIT_SUCCESS);
}
