/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   defenitions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:02:51 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/31 14:30:04 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFENITIONS_H
# define DEFENITIONS_H
# include "cub3d.h"

/*
**------------------------------X11 EVENTS--------------------------------------
*/

# define KEYPRESS 2
# define KEYRELEASE 3
# define DESTROY 17

# define PRESS_MASK 1L<<0
# define RELEASE_MASK 1L<<1

/*
**------------------------------KEY CODES--------------------------------------
*/

# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

# define LEFT_KEY 123
# define RIGHT_KEY 124

/*
**-----------------------------------MLX----------------------------------------
*/
# define WINDOW data->mlx_data.mlx_win

# define MLX data->mlx_data.mlx

# define IMG_ONE data->mlx_data.image_one.img
# define IMG_TWO data->mlx_data.image_two.img

# define ADDRES_ONE data->mlx_data.image_one.addr
# define ADDRES_TWO data->mlx_data.image_two.addr

# define BPP_ONE data->mlx_data.image_one.bits_per_pixel
# define BPP_TWO data->mlx_data.image_two.bits_per_pixel

# define LL_ONE data->mlx_data.image_one.line_length
# define LL_TWO data->mlx_data.image_two.line_length

# define ENDIAN_ONE data->mlx_data.image_one.endian
# define ENDIAN_TWO data->mlx_data.image_two.endian

/*
**----------------------------------DATA----------------------------------------
*/

# define WIDTH data->resolution.x
# define HEIGHT data->resolution.y

# define MAP data->map.map

/*
**------------------------------RAY CASTING-------------------------------------
*/

# define CAM_X data->raycasting.camera_x

# define MAP_X data->raycasting.map.x
# define MAP_Y data->raycasting.map.y

# define POS_X data->raycasting.pos.x
# define POS_Y data->raycasting.pos.y

# define DELTA_DIS_X data->raycasting.delta_distance.x
# define DELTA_DIS_Y data->raycasting.delta_distance.y

# define DIR_X data->raycasting.direction.x
# define DIR_Y data->raycasting.direction.y

# define RAY_DIR_X data->raycasting.ray_direction.x
# define RAY_DIR_Y data->raycasting.ray_direction.y

# define SIDE_DIS_X data->raycasting.side_distance.x
# define SIDE_DIS_Y data->raycasting.side_distance.y

# define PLANE_X data->raycasting.plane.x
# define PLANE_Y data->raycasting.plane.y

# define STEP_X data->raycasting.step.x
# define STEP_Y data->raycasting.step.y

# define WALL_DIS data->raycasting.perp_wall_distance

# define SIDE data->raycasting.side

# define LINE_HEIGHT data->raycasting.lineheight
# define DRAW_START data->raycasting.draw_start
# define DRAW_END data->raycasting.draw_end

/*
**--------------------------------MOVEMENT--------------------------------------
*/

# define OLD_DIR_X data->raycasting.old_direction.x
# define OLD_DIR_Y data->raycasting.old_direction.y

# define OLD_PLANE_X data->raycasting.old_plane.x
# define OLD_PLANE_Y data->raycasting.old_plane.y

# define FORWARD data->raycasting.move.forward
# define BACKWARD data->raycasting.move.backward

# define LOOK_LEFT data->raycasting.move.turn_left
# define LOOK_RIGHT data->raycasting.move.turn_right

# define MOVE_LEFT data->raycasting.move.move_left
# define MOVE_RIGHT data->raycasting.move.move_right

/*
**--------------------------------TEXTURE---------------------------------------
*/

# define IMG_north data->texture_data.north_texture.image.img
# define IMG_east data->texture_data.east_texture.image.img
# define IMG_west data->texture_data.west_texture.image.img
# define IMG_south data->texture_data.south_texture.image.img

# define ADDRES_north data->texture_data.north_texture.image.addr
# define ADDRES_east data->texture_data.east_texture.image.addr
# define ADDRES_west data->texture_data.west_texture.image.addr
# define ADDRES_south data->texture_data.south_texture.image.addr

# define PATH_north data->texture_data.north_texture.path
# define PATH_east data->texture_data.east_texture.path
# define PATH_west data->texture_data.west_texture.path
# define PATH_south data->texture_data.south_texture.path

# define BPP_north data->texture_data.north_texture.image.bits_per_pixel
# define BPP_east data->texture_data.east_texture.image.bits_per_pixel
# define BPP_west data->texture_data.west_texture.image.bits_per_pixel
# define BPP_south data->texture_data.south_texture.image.bits_per_pixel

# define LL_north data->texture_data.north_texture.image.line_length
# define LL_east data->texture_data.east_texture.image.line_length
# define LL_west data->texture_data.west_texture.image.line_length
# define LL_south data->texture_data.south_texture.image.line_length

# define ENDIAN_north data->texture_data.north_texture.image.endian
# define ENDIAN_east data->texture_data.east_texture.image.endian
# define ENDIAN_west data->texture_data.west_texture.image.endian
# define ENDIAN_south data->texture_data.south_texture.image.endian

# define TEX_HEIGHT_north data->texture_data.north_texture.tex_resolution.x
# define TEX_HEIGHT_east data->texture_data.east_texture.tex_resolution.x
# define TEX_HEIGHT_west data->texture_data.west_texture.tex_resolution.x
# define TEX_HEIGHT_south data->texture_data.south_texture.tex_resolution.x

# define TEX_WIDTH_north data->texture_data.north_texture.tex_resolution.y
# define TEX_WIDTH_east data->texture_data.east_texture.tex_resolution.y
# define TEX_WIDTH_west data->texture_data.west_texture.tex_resolution.y
# define TEX_WIDTH_south data->texture_data.south_texture.tex_resolution.y

# define WALL_X_north data->texture_data.north_texture.wallX
# define WALL_X_east data->texture_data.east_texture.wallX
# define WALL_X_west data->texture_data.west_texture.wallX
# define WALL_X_south data->texture_data.south_texture.wallX

# define TEX_X_north data->texture_data.north_texture.texX
# define TEX_X_east data->texture_data.east_texture.texX
# define TEX_X_west data->texture_data.west_texture.texX
# define TEX_X_south data->texture_data.south_texture.texX

# define TEX_Y_north data->texture_data.north_texture.texY
# define TEX_Y_east data->texture_data.east_texture.texY
# define TEX_Y_west data->texture_data.west_texture.texY
# define TEX_Y_south data->texture_data.south_texture.texY

# define TEX_POS_north data->texture_data.north_texture.texPos
# define TEX_POS_east data->texture_data.east_texture.texPos
# define TEX_POS_south data->texture_data.south_texture.texPos
# define TEX_POS_west data->texture_data.west_texture.texPos

# define TEX_STEP_north data->texture_data.north_texture.step
# define TEX_STEP_east data->texture_data.east_texture.step
# define TEX_STEP_south data->texture_data.south_texture.step
# define TEX_STEP_west data->texture_data.west_texture.step

# define TEX_COLOR_north data->texture_data.north_texture.color
# define TEX_COLOR_east data->texture_data.east_texture.color
# define TEX_COLOR_south data->texture_data.south_texture.color
# define TEX_COLOR_west data->texture_data.west_texture.color

/*
**--------------------------------SPRITES---------------------------------------
*/

# define IMG_SPRITE data->texture_data.sprite_texture.image.img
# define ADDRES_SPRITE data->texture_data.sprite_texture.image.addr
# define BPP_SPRITE data->texture_data.sprite_texture.image.bits_per_pixel
# define LL_SPRITE data->texture_data.sprite_texture.image.line_length
# define ENDIAN_SPRITE data->texture_data.sprite_texture.image.endian

# define PATH_SPRITE data->texture_data.sprite_texture.path

# define PATH_HEIGHT data->texture_data.sprite_texture.tex_resolution.x
# define PATH_WIDTH data->texture_data.sprite_texture.tex_resolution.y

# define TEX_HEIGHT_SPRITE data->texture_data.sprite_texture.sprite_resolution.x
# define TEX_WIDTH_SPRITE data->texture_data.sprite_texture.sprite_resolution.y

# define SPRITE_AMOUNT data->texture_data.sprite_texture.amount_of_sprites

# define SPRITE_X data->texture_data.sprite_texture.spriteX
# define SPRITE_Y data->texture_data.sprite_texture.spriteY

# define MATRIX data->texture_data.sprite_texture.matrix

# define TRANSFORM_X data->texture_data.sprite_texture.transformX
# define TRANSFORM_Y data->texture_data.sprite_texture.transformY

# define SPLITSCREEN_X data->texture_data.sprite_texture.splitscreenX

# define SPRITE_HEIGHT data->texture_data.sprite_texture.sprite_height
# define SPRITE_WIDTH data->texture_data.sprite_texture.sprite_width

# define DRAW_START_X data->texture_data.sprite_texture.draw_start_x
# define DRAW_START_Y data->texture_data.sprite_texture.draw_start_y

# define DRAW_END_X data->texture_data.sprite_texture.draw_end_x
# define DRAW_END_Y data->texture_data.sprite_texture.draw_end_y

# define STRIPE data->texture_data.sprite_texture.stripe

# define TEX_X_SPRITE data->texture_data.sprite_texture.texX_sprite
# define TEX_Y_SPRITE data->texture_data.sprite_texture.texY_sprite

# define SPRITE_COLOR data->texture_data.sprite_texture.color

#endif
