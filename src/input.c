/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:55:47 by home              #+#    #+#             */
/*   Updated: 2021/05/28 20:35:28 by home             ###   ########.fr       */
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

		(SDLX_iMap){&BMAP(button_A), 1, SDL_SCANCODE_KP_ENTER},
		(SDLX_iMap){&BMAP(button_A), 1, SDL_SCANCODE_SPACE},
		(SDLX_iMap){&BMAP(button_A), 1, SDL_SCANCODE_RETURN},

	};

	*size = sizeof(key_map) / sizeof(*key_map);
	return (&key_map[0]);
}
