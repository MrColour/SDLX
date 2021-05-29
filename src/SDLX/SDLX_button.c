/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDLX_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 01:10:16 by home              #+#    #+#             */
/*   Updated: 2021/05/28 19:31:34 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDLX.h"

int	SDLX_init_button(SDLX_button *dst, int (*sprite_fn)(SDLX_Sprite_Data **, int), int sprite_no, SDL_Rect placement, SDLX_RenderQueue *render_dst)
{
	dst->sprite_fn = sprite_fn;
	SDLX_new_Sprite(&(dst->sprite));
	dst->sprite._dst = placement;

	dst->sprite_fn(&(dst->sprite.sprite_data), sprite_no);

	dst->render_dst = render_dst;
	dst->trigger_box = dst->sprite._dst;

	dst->disabled = -1;
	dst->norm_no = -1;
	dst->focus_no = -1;

	dst->focused = SDL_FALSE;

	return (EXIT_SUCCESS);
}

void	SDLX_style_button(SDLX_button *button, int norm, int hover)
{
	button->focus_no = hover;
	button->norm_no = norm;
}

/*
// Updates the button based on the data saved in the button class.
// The button has functions for on trigger, on focus, continued focus#include "../aoc++.h"
// These function should go after all changes, allowing the user to revert
// them if they do not want the automatic changes. This also allows the user to
// create a copy and be able to preform shallow copies.
*/

void	SDLX_update_button(SDLX_button *button)
{
	if (button->mouse != NULL && SDL_PointInRect(button->mouse, &(button->trigger_box))) //This could be 'in focus triggers'
	{
		if (button->focused == SDL_FALSE) // This activates on-hover, aka once
		{
			// Onceler function activates here.
			if (button->focus_no != -1)
			{
				button->sprite_fn(&(button->sprite.sprite_data), button->focus_no);
				button->sprite.current = 0;
			}
			button->focused = SDL_TRUE;
		}
		// else //This continues to activate on hover

		// always active
	}
	else if (button->focused == SDL_TRUE) // Was focused but no longer
	{
		if (button->norm_no != -1)
		{
			button->sprite_fn(&(button->sprite.sprite_data), button->norm_no);
			button->sprite.current = 0;
		}
		button->focused = SDL_FALSE;
	}

	SDLX_RenderQueue_add(button->render_dst, &(button->sprite));
	button->sprite.current++;
}