/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:36:41 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/25 16:45:46 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int handle_key(int keycode, t_game *data)
{
    if (keycode == W)
        return (data->player_y - 1);
    else if (keycode == S)
        return (data->player_y + 1);
    else if (keycode == A)
        return (data->player_x - 1);
    else if (keycode == D)
        return (data->player_x + 1);
    // else if (keycode == ESC)
    //     return ();
    // else if (keycode == ESC)
    //     return ();
}

void    init_move_input(t_game *data)
{
    mlx_key_hook(data->win, &handle_key, data);
}