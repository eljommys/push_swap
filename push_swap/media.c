/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   media.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:35:39 by marvin            #+#    #+#             */
/*   Updated: 2021/03/14 14:35:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../minilibft.h"

int	get_mean(int *a, int size)
{
	int result;

	result = 0;
	for (int i = 0; i < size; i++)
		result += a[i];
	result /= size;
	return result;
}

int	get_index(int *a, int size, int mean)
{
	int index;
	int diff;
	int aux;

	index = 0;
	diff = (a[0] - mean < 0) ? (a[0] - mean) * -1 : a[0] - mean;
	for (int i = 1; i < size; i++)
	{
		aux = (a[i] - mean < 0) ? (a[i] - mean) * -1 : a[i] - mean;
		if (aux < diff)
		{
			index = i;
			diff = aux;
		}
	}
	return index;
}

void	show_array(int *a, int size)
{
	for (int i = 0; i < size && printf(" "); i++)
		printf("%d", a[i]);
}

void	order(int *a, int size)
{
	int i;
	int	aux;
	int bef;
	int aft;

	if (size <= 1)
		return ;
	i = get_index(a, size, get_mean(a, size));
	aux = a[(size - 1) / 2];
	a[(size - 1) / 2] = a[i];
	a[i] = aux;

	bef = -1;
	aft = (size - 1) / 2 + 1;
	while (++bef < size / 2)
	{
		while (a[aft] > a[(size - 1) / 2] && aft < size)
			aft++;
		if (aft < size)
		{
			aux = a[bef];
			a[bef] = a[aft];
			a[aft] = aux;
		}
	}
	order(a, size / 2);
	if (size % 2)
		order(a + size / 2, size / 2 + 1);
	else
		order(a + size / 2, size / 2);
}

int main(int argc, char **argv)
{
	//int mean;
	int	a[argc - 1];
	//int index;

	for (int i = 1; i < argc; i++)
		a[i - 1] = ft_atoi(argv[i]);
	//mean = get_mean(a, argc - 1);
	//index = get_index(a, argc - 1, mean);
	order(a, argc - 1);

	show_array(a, argc - 1);
	/*printf("media = %d\n", mean);
	printf("pivot = %d\n", a[index]);
	printf("index should be at %d and is %d\n", (argc - 1) / 2, index);*/
}
