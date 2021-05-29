/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:55:47 by home              #+#    #+#             */
/*   Updated: 2021/05/27 22:59:34 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDLX.h"

SDLX_iMap	*menu_key_map(size_t *size)
{
	static SDLX_iMap	key_map[] =
	{
		(SDLX_iMap){&BMAP(button_DPAD_UP), 1, SDL_SCANCODE_W},
		(SDLX_iMap){&BMAP(button_DPAD_LEFT), 1, SDL_SCANCODE_A},
		(SDLX_iMap){&BMAP(button_DPAD_DOWN), 1, SDL_SCANCODE_S},
		(SDLX_iMap){&BMAP(button_DPAD_RIGHT), 1, SDL_SCANCODE_D},

		(SDLX_iMap){&BMAP(button_DPAD_UP), 1, SDL_SCANCODE_UP},
		(SDLX_iMap){&BMAP(button_DPAD_LEFT), 1, SDL_SCANCODE_LEFT},
		(SDLX_iMap){&BMAP(button_DPAD_DOWN), 1, SDL_SCANCODE_DOWN},
		(SDLX_iMap){&BMAP(button_DPAD_RIGHT), 1, SDL_SCANCODE_RIGHT},

		(SDLX_iMap){&BMAP(button_B), 1, SDL_SCANCODE_B},
		(SDLX_iMap){&BMAP(button_A), 1, SDL_SCANCODE_A},
	};

	*size = sizeof(key_map) / sizeof(*key_map);
	return (&key_map[0]);
}
