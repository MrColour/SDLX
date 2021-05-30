/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:38:32 by home              #+#    #+#             */
/*   Updated: 2021/05/21 00:54:05 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef main_H
# define main_H

# include <SDL_image.h>

# include "SDLX.h"

# define ASSETS "assets/"

enum	UI_SPRITES
{
	START_NORM,
	START_HOVER,
	SOUND_NORM,
	SOUND_HOVER,
	EXIT_NORM,
	EXIT_HOVER,
};

typedef struct	s_context
{
	SDLX_Sprite			background;
	SDLX_RenderQueue	rQueue;

	int					ticks;

	SDLX_button			start_button;
	SDLX_button			sound_button;
	SDLX_button			exit_button;
}				t_context;

int			fetch_ui_sprite(SDLX_Sprite_Data **dst, int no);

SDLX_iMap	*menu_key_map(size_t *size);

#endif
