/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carve_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 19:51:55 by home              #+#    #+#             */
/*   Updated: 2020/07/06 20:05:58 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

SDL_Rect	*carve__texture(void)
{
	int			row;
	int			col;
	SDL_Rect	*result;

	row = 0;
	result = malloc(sizeof(*result) * (NAN_VAL * NAN_VAL));
	while (row < NAN_VAL)
	{
		col = 0;
		while (col < NAN_VAL)
		{
			result[row * 3 + col].h = NAN_VAL;
			result[row * 3 + col].w = NAN_VAL;
			result[row * 3 + col].x = (col * NAN_VAL);
			result[row * 3 + col].y = (row * NAN_VAL);
			col++;
		}
		row++;
	}
	return (result);
}
