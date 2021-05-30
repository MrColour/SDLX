/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:12:02 by home              #+#    #+#             */
/*   Updated: 2021/05/29 21:49:34 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

SDLX_Sprite_Data	*carve_ui_sprite(void)
{
	size_t				i;
	size_t				j;
	SDL_Texture			*texture;
	SDLX_Sprite_Data	*result;

	result = SDL_calloc(6 * 9, sizeof(*result));

	texture = IMG_LoadTexture(SDLX_GetDisplay()->renderer, ASSETS"starto.png");
	if (texture == NULL)
		SDL_Log("NULL Texture");

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 8)
		{
			result[i * 8 + j].texture = texture;
			result[i * 8 + j]._src = (SDL_Rect){j * 32, i * 16, 32, 16};
			result[i * 8 + j].src = &(result[i * 8 + j]._src);
			result[i * 8 + j].cycle = 8;

			j++;
		}
		i++;
	}
	result[3 * 8 + 7].skip = 5;
	return (result);
}

int		fetch_ui_sprite(SDLX_Sprite_Data **dst, int no)
{
	static SDLX_Sprite_Data	*sprite_arr;

	if (sprite_arr == NULL)
		sprite_arr = carve_ui_sprite();

	if (no == START_NORM)       { (*dst) = &(sprite_arr[0 * 8]); return (EXIT_SUCCESS); }
	else if (no == START_HOVER) { (*dst) = &(sprite_arr[1 * 8]); return (EXIT_SUCCESS); }
	else if (no == EXIT_NORM)   { (*dst) = &(sprite_arr[2 * 8]); return (EXIT_SUCCESS); }
	else if (no == EXIT_HOVER)  { (*dst) = &(sprite_arr[3 * 8]); return (EXIT_SUCCESS); }
	else if (no == SOUND_NORM)  { (*dst) = &(sprite_arr[4 * 8]); return (EXIT_SUCCESS); }
	else if (no == SOUND_HOVER) { (*dst) = &(sprite_arr[5 * 8]); return (EXIT_SUCCESS); }
	else { return (EXIT_FAILURE); }
}
