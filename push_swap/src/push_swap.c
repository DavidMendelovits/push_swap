/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:15:00 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/09 14:10:49 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			push_to_back(t_stack **head, int num)
{
	t_stack				*traverse;
	t_stack				*new;

	new = (t_stack *)malloc(sizeof(*new));
	new->num = num;
	new->next = NULL;
	traverse = *head;
	if (!(*head))
	{
		*head = new;
		return ;
	}
	while (traverse && traverse->next)
	{
		traverse = traverse->next;
	}
	traverse->next = new;
}

void			push_to_front(t_stack **head, int num)
{
	t_stack				*new;

	new = (t_stack *)malloc(sizeof(*new));
	new->num = num;
	if (!(*head))
	{
		new->next = NULL;
	}
	else
	{
		new->next = *head;
	}
	*head = new;
}

int				pop(t_stack **head)
{
	int					popped;
	t_stack				*new_head;

	if (!(*head))
		return (0);
	popped = (*head)->num;
	new_head = (*head)->next;
	free(*head);
	*head = new_head;
	return (popped);
}

void			print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack)
	{
		printf("|%.10d|\n", stack->num);
	}
	if (stack->next)
	{
		print_stack(stack->next);
	}
}

int				is_num(char *s)
{
	int					p;

	p = 0;
	if (s[0] == '-')
		p += 1;
	while (s[p])
	{
		if (!ft_is_digit(s[p]))
		{
			return (0);
		}
		p += 1;
	}
	return (1);
}

void			ft_swap(int *a, int *b)
{
	int					tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			sb(t_stack *head)
{
	ft_swap(&head->num, &head->next->num);
	write(1, "sb\n", 3);
}

void			sa(t_stack *head)
{
	ft_swap(&head->num, &head->next->num);
	write(1, "sa\n", 3);
}

void			ss(t_stack *a, t_stack *b)
{
	ft_swap(&a->num, &a->next->num);
	ft_swap(&b->num, &b->next->num);
	write(1, "ss\n", 3);
}

void			push_ab(t_stack **a, t_stack **b)
{
	int					num;

	num = pop(b);
	push_to_front(a, num);
}

void			pa(t_stack **a, t_stack **b)
{
	push_ab(a, b);
	write(1, "pa\n", 3);
}

void			pb(t_stack **b, t_stack **a)
{
	push_ab(b, a);
	write(1, "pb\n", 3);
}

void			rotate_up(t_stack **stack)
{
	int					front;
	t_stack				*traverse;

	traverse = *stack;
	front = traverse->num;
	while (traverse && traverse->next)
	{
		ft_swap(&traverse->num, &traverse->next->num);
		traverse = traverse->next;
	}
}

void			ra(t_stack **a)
{
	rotate_up(a);
	write(1, "ra\n", 3);
}

void			rb(t_stack **b)
{
	rotate_up(b);
	write(1, "rb\n", 3);
}


void			rr(t_stack **a, t_stack **b)
{
	rotate_up(a);
	rotate_up(b);
	write(1, __func__, sizeof(__func__));
}

void			rotate_down(t_stack **stack)
{
	t_stack				*traverse;
	int					tmp;

	traverse = *stack;
	while (traverse && traverse->next)
	{
		traverse = traverse->next;
	}
	tmp = traverse->num;
	traverse = *stack;
	while (traverse)
	{
		ft_swap(&traverse->num, &tmp);
		traverse = traverse->next;
	}
}

void			rra(t_stack **a)
{
	rotate_down(a);
	write(1, __func__, sizeof(__func__));
	write(1, "\n", 1);
}

void			rrb(t_stack **b)
{
	rotate_down(b);
	write(1, __func__, sizeof(__func__));
	write(1, "\n", 1);
}

void			rrr(t_stack **a, t_stack **b)
{
	rotate_down(a);
	rotate_down(b);
	write(1, __func__, sizeof(__func__));
}

void			print_ints(int *set, int n)
{
	int					i;

	i = 0;
	while (i < n)
	{
		printf("%d\n", set[i]);
		i += 1;
	}
}

void			sort_ints(int **set, int n)
{
	int					*local;
	int					sorted;
	int					p;

	local = *set;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		p = n - 1;
		while (p > 0)
		{
			if (local[p] < local[p - 1])
			{
				ft_swap(&local[p], &local[p - 1]);
				sorted = 0;
			}
			p -= 1;
		}
	}
}

int				find_median(int *set, int n)
{
	sort_ints(&set, n);
//	print_ints(set, n);
	return (set[n / 2]);
}

void			insert_aux(t_stack **a, t_stack **b)
{
	if ((*b) && (*b)->num > (*a)->num)
	{
		pb(b, a);
		sb(*b);
	}
	else
	{
		pb(b, a);
	}
}

t_stack			*split_stacks(t_stack **a, int a_len, int median)
{
	int					p;
	t_stack 			*b;
	int					b_len;

	b_len = 0;
	b = NULL;
	p = 0;
	while (p < a_len)
	{
		if ((*a)->num < median)
		{
			insert_aux(a, &b);
//			pb(&b, a);
		}
		else
		{
			ra(a);
		}
		p += 1;
	}
	return (b);
}

void			sort_a(t_stack **a, t_stack *b)
{
	int					sorted;

	sorted = 0;
	while (!sorted)
	{

	}
}

void			sort(t_stack **a, int *num_set, int len)
{
	int					median;
	t_stack				*b;

	b = NULL;
	median = find_median(num_set, len - 1);
	printf("median = %d\n", median);
	b = split_stacks(a, len, median);	
	print_stack(*a);
	printf("a^---------b>\n");
	print_stack(b);
	sort_a(a, &b);
}

int				push_swap(int argc, char **argv)
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	int					*set;
	int					p;
	int					i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	p = 1;
	set = malloc(sizeof(int) * (argc - 1));
	while (p < argc)
	{
		if (is_num(argv[p]))
		{
			push_to_back(&stack_a, ft_atoi(argv[p]));
			set[i++] = ft_atoi(argv[p]);
		}
		else
		{
			return (0);
		}
		p += 1;
	}
	print_stack(stack_a);
	sort(&stack_a, set, p);
	return (1);
}

int				main(int argc, char **argv)
{
	printf("------------------------------------\n");
	printf("P U S H I T R E A L G O O D\n");
	printf("------------------------------------\n");
	
	if (argc > 1)
	{
		if (!push_swap(argc, argv))
		{
			write(2, INPUT_ERR, sizeof(INPUT_ERR));
			return (1);
		}
	}
	return (0);
}	
