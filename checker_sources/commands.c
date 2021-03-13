/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:39:47 by marvin            #+#    #+#             */
/*   Updated: 2021/03/13 12:39:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(char to, int *a, int *b, int *a_b)
{
	if ((to == 'a' && a_b[0] < 2) || (to == 'b' && a_b[1] < 2))
		return ;
	if (to == 'a')
		switch_num(&a[0], &a[1]);
	else if (to == 'b')
		switch_num(&b[0], &b[1]);
	else
	{
		switch_num(&a[0], &a[1]);
		switch_num(&b[0], &b[1]);
	}
}

void	push(char to, int *a, int *b, int *a_b)
{
	int		i;

	if (to == 'a' && a_b[1] > 0)
	{
		a_b[0]++;
		i = a_b[0];
		while (--i >= 0)
			a[i] = a[i - 1];
		a[0] = b[0];
		i = -1;
		while (++i < a_b[1] - 1)
			b[i] = b[i + 1];
		a_b[1]--;
	}
	else if (to == 'b' && a_b[0] > 0)
	{
		switch_num(&a_b[0], &a_b[1]);
		push('a', b, a, a_b);
		switch_num(&a_b[0], &a_b[1]);
	}
}

void	rotate(char to, int *a, int *b, int *a_b)
{
	int		aux;
	int		i;

	if (to == 'a')
	{
		aux = a[0];
		i = -1;
		while (++i < a_b[0] - 1)
			a[i] = a[i + 1];
		a[i] = aux;
	}
	else if (to == 'r')
	{
		switch_num(&a_b[0], &a_b[1]);
		rotate('b', b, a, a_b);
		switch_num(&a_b[0], &a_b[1]);
	}
}

void	r_rotate(char to, int *a, int *b, int *a_b)
{
	int		aux;
	int		i;

	if (to == 'a')
	{
		aux = a[a_b[0] - 1];
		i = a_b[0];
		while (--i >= 0)
			a[i] = a[i - 1];
		a[0] = aux;
	}
	else if (to == 'r')
	{
		switch_num(&a_b[0], &a_b[1]);
		r_rotate('b', b, a, a_b);
		switch_num(&a_b[0], &a_b[1]);
	}
}
