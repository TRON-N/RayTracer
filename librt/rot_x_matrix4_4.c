/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_x_matrix4_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-gen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 11:45:08 by lvan-gen          #+#    #+#             */
/*   Updated: 2017/09/26 11:45:12 by lvan-gen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

void	rot_x_matrix4_4(t_matrix4_4 matrix, double deg)
{
	double	rad;

	rad = DEG_TO_RAD(deg);
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(rad);
	matrix[1][2] = sin(rad);
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = -sin(rad);
	matrix[2][2] = cos(rad);
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}
