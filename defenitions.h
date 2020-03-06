/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defenitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:02:51 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/06 15:33:25 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**----------------------------------DATA----------------------------------------
*/

#define WIDTH data->resolution.x
#define HEIGHT data->resolution.y

#define MAP data->map

/*
**------------------------------RAY CASTING-------------------------------------
*/

#define CAM_X raycasting->camera_x

#define MAP_X raycasting->map.x
#define MAP_Y raycasting->map.y

#define POS_X raycasting->pos.x
#define POS_Y raycasting->pos.y

#define DELTA_DIS_X raycasting->delta_distance.x
#define DELTA_DIS_Y raycasting->delta_distance.y

#define DIR_X raycasting->direction.x
#define DIR_Y raycasting->direction.y

#define RAY_DIR_X raycasting->ray_direction.x
#define RAY_DIR_Y raycasting->ray_direction.y

#define SIDE_DIS_X raycasting->side_distance.x
#define SIDE_DIS_Y raycasting->side_distance.y

#define PLANE_X raycasting->plane.x
#define PLANE_Y raycasting->plane.y

#define STEP_X raycasting->step.x
#define STEP_Y raycasting->step.y

#define WALL_DIS raycasting->perp_wall_distance
