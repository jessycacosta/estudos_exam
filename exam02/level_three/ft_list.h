/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:04:42 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/24 19:08:06 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_SIZE
#define LIST_SIZE

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
#endif