#include"ei_geometrymanager.h"

// typedef void	(*ei_geometrymanager_runfunc_t)		(struct ei_widget_t*	widget);
// typedef void	(*ei_geometrymanager_releasefunc_t)	(struct ei_widget_t*	widget);

// création de la structure ei_geometryplacer_t de type ei_geometrymanager_t
// il faut y mettre les pointeurs vers les fonctions du gestionnaire
// je comprends pas si ça doit être ei_geometryplacer_t ou ei_geometrymanager_t
// typedef struct ei_geometrymanager_t {
// 	ei_geometry_param_t param;
//
// } ei_geometryplacer_t;
// il faut runfunc et releasefunc ( name et next ?) voir ei_geometrymanager_t
// pour
//il faut enregistrer le gestionnaire pas un appel a ei_geometrymanager_register
//ei_geometrymanager_register(&lenomdecequejeviensdedefinir)

void			ei_geometrymanager_register	(ei_geometrymanager_t* geometrymanager)
{

}

ei_geometrymanager_t*	ei_geometrymanager_from_name	(ei_geometrymanager_name_t name)
{

}

void			ei_geometrymanager_unmap	(ei_widget_t*		widget)
{

}

void 			ei_register_placer_manager 	()
{

}

void			ei_place			(ei_widget_t*		widget,
							 ei_anchor_t*		anchor,
							 int*			x,
							 int*			y,
							 int*			width,
							 int*			height,
							 float*			rel_x,
							 float*			rel_y,
							 float*			rel_width,
							 float*			rel_height)
{

}
