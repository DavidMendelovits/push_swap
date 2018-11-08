/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:17:40 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/07 16:56:08 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>

# define INPUT_ERR "Error\n"

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

int					push_swap(int argc, char **argv);

#endif
