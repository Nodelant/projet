#include "ei_frame.h"
#include <stdlib.h>
#include "ei_types.h"
#include "ei_widgetclass.h"

/**
  *\brief allocate the memory for frame
 */
void* ei_frame_allocfunc_t()
{
        return malloc(sizeof(ei_frame_t));
}

/**
 * \brief	A function that draws widgets of a class.
 *
 * @param	widget		A pointer to the widget instance to draw.
 * @param	surface		Where to draw the widget. The actual location of the widget in the
 *				surface is stored in its "screen_location" field.
 * @param	pick_surface	The surface used for picking (i.e. find the widget below the mouse pointer).
 * @param	clipper		If not NULL, the drawing is restricted within this rectangle
 *				(expressed in the surface reference frame).
 */
void ei_frame_drawfunc_t(struct ei_widget_t*	widget,
    							ei_surface_t	surface,
    					        ei_surface_t	pick_surface,
    							ei_rect_t*		clipper)
{
        ei_fill(surface, ((ei_frame_t*)widget) -> color, clipper);  ///< filling the frame with its color
        if (((ei_frame_t*)widget) -> text != NULL ){
                //TODO : probleme avec ei_drawtext : argument "where" = point. ancrage = enum
                // cf ei_draw.c
                //TODO : CE QUI A ETE FAIT N'EST PAS FAIT DANS L'OFFSCREEN ENCORE
                ei_point_t* point = associate_point_anchor(((ei_frame_t*)widget) -> anchor_text, surface);
                ///< adressing the top-left corner as a point from its anchor
                ei_draw_text(surface, \
                            point, \
                            ((ei_frame_t*)widget) -> text, \
                            ((ei_frame_t*)widget) -> font, \
                            ((ei_frame_t*)widget) -> color_text, \
                            clipper); ///< Drawing said text
        }
        if (((ei_frame_t*)widget) -> image != NULL){
                ei_copy_surface (surface, \
                                clipper, \
                                ((ei_frame_t*)widget) -> image, \
                                ((ei_frame_t*)widget) -> rect, \
                                hw_surface_has_alpha(((ei_frame_t*)widget) -> image)); ///< drawing image if exists
        }
}

/**
 * \brief	A function that releases the memory used by a FRAME widget before it is destroyed.
 *		The \ref ei_widget_t structure itself, passed as parameter, must *not* by freed by
 *		these functions. Can be set to NULL in \ref ei_widgetclass_t if no memory is used by
 *		a class of widget.
 *
 * @param	widget		The widget which resources are to be freed.
 */
void ei_frame_releasefunc_t(struct ei_widget_t* widget)
{
        free(((ei_frame_t*)widget) -> color);
        free(((ei_frame_t*)widget) -> border_width);
        free(((ei_frame_t*)widget) -> relief);
        free(((ei_frame_t*)widget) -> text);
        free(((ei_frame_t*)widget) -> font);
        free(((ei_frame_t*)widget) -> color_text);
        free(((ei_frame_t*)widget) -> anchor_text);
        free(((ei_frame_t*)widget) -> image);
        free(((ei_frame_t*)widget) -> rect);
        free(((ei_frame_t*)widget) -> anchor_image);
}

void ei_frame_setdefaultsfunc_t(struct ei_widget_t*   widget)
{
        ei_color_t default_color = ei_default_background_color;
        ei_color_t text_defaut_color = ei_font_default_color;
        ((ei_frame_t*)widget) -> color = &default_color;
        ((ei_frame_t*)widget) -> font = &ei_default_font;
        ((ei_frame_t*)widget) -> color_text = &text_defaut_color;
}
