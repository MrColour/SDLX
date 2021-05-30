#ifndef SDLX_H
#define SDLX_H

# include "SDL2/SDL.h"
# include "SDL2/SDL_image.h"

# include "SDLX_const.h"
# include "SDLX_config.h"
# include "SDLX_ticks.h"

# include "SDLX_structs.h"

void			SDLX_start(SDLX_Display *dest);

SDLX_Display	*SDLX_GetDisplay(void);

void			SDLX_screen_reset(SDL_Renderer *renderer, SDL_Color *bg_color);

void			SDLX_close(void);

void			SDLX_draw_animation(SDL_Renderer *renderer, SDLX_Sprite *animation);

int				SDLX_RenderQueue_init(SDLX_RenderQueue *dest);
void			SDLX_RenderQueue_add(SDLX_RenderQueue *dst, SDLX_Sprite *src);
void			SDLX_RenderQueue_flush(SDLX_RenderQueue *queue, SDL_Renderer *renderer);

int				SDLX_AxisConvert(SDL_Point *axis);
void			SDLX_FillXbox_Axis(SDLX_GameInput *game_input, SDL_GameController *controller);
void			SDLX_toDPAD(SDLX_GameInput *game_input, int set);
void			SDLX_GameInput_Mouse_Fill(SDLX_GameInput *dst, SDL_bool convert);
void			SDLX_record_input(SDLX_GameInput *from);

SDL_GameController	*SDLX_XboxController_link(int player_no);

void	SDLX_KeyMap(SDLX_input_mapper *key_map, const Uint8 *keystate);
void	SDLX_ControllerMap(SDLX_input_mapper *key_map, SDL_GameController *controller);

SDLX_direction	SDLX_reverse_dir(SDLX_direction direction);
SDLX_Sprite		*SDLX_new_Sprite(SDLX_Sprite *dst);

SDLX_Sprite		*SDLX_get_background(void);
void			SDLX_set_background(SDLX_Sprite *src);

SDL_bool		SDLX_poll(void);

void			SDLX_Mouse_to_Screen(int *x, int *y);

int				SDLX_init_button(SDLX_button *dst, int (*sprite_fn)(SDLX_Sprite_Data **, int),
					int sprite_no, SDL_Rect placement, SDLX_RenderQueue *render_dst);

void			SDLX_update_button(SDLX_button *button);
void			SDLX_style_button(SDLX_button *button, int norm, int hover);
void			*SDLX_button_null_fn(SDL_UNUSED SDLX_button *button, SDL_UNUSED void *meta, SDL_UNUSED size_t meta_length);
SDL_bool		SDLX_Button_onHoverFocus(SDLX_button *self, SDL_UNUSED void *meta, SDL_UNUSED size_t meta_length);
void			SDLX_Button_set_fn(SDLX_button *button,
								SDL_bool (*get_focus_fn)(struct SDLX_button *, void *, size_t),
								void *(*focus_fn)(struct SDLX_button *, void *, size_t),
								void *(*focus_once_fn)(struct SDLX_button *, void *, size_t),
								void *(*trigger_fn)(struct SDLX_button *, void *, size_t),
								void *(*update_fn)(struct SDLX_button *, void *, size_t));

#endif
