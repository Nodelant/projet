/**
 *  @file	ei_draw.c
 *  @brief	Graphical primitives to text, and operation of drawing
 *		surface
 *
 *  \author
 *  Created by thomas, lucas, basile on 18.05.18.
 *
 */

#include "ei_draw.h"
/**
 * \brief	Draws text by calling \ref hw_text_create_surface.
 *
 * @param	surface 	Where to draw the text. The surface must be *locked* by
 *				\ref hw_surface_lock.
 * @param	where		Coordinates, in the surface, where to anchor the top-left corner of
 *				the rendered text.
 * @param	text		The string of the text. Can't be NULL.
 * @param	font		The font used to render the text. If NULL, the \ref ei_default_font
 *				is used.
 * @param	color		The text color. The alpha parameter is not used.
 * @param	clipper		If not NULL, the drawing is restricted within this rectangle.
 */
void			ei_draw_text		(ei_surface_t		surface,
						 const ei_point_t*	where,
						 const char*		text,
						 const ei_font_t	font,
						 const ei_color_t	color,
						 const ei_rect_t*	clipper)
{
//TODO : ei draw text à implementer
}

ei_point_t* associate_point_anchor  (enum ei_anchor_t    anchor,
                                    ei_surface_t    surface)
{
    //TODO : association ancrage-surface avec coordonnées
}
