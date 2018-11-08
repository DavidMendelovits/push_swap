/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:15:00 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/07 19:48:15 by dmendelo         ###   ########.fr       */
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

int				find_median(t_stack *a)
{
//maybe harder than I thought
}

void			sort(t_stack **a, int len)
{
	int					median;

	median = find_median(*a);
}

int				push_swap(int argc, char **argv)
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	int					p;

	stack_a = NULL;
	stack_b = NULL;
	p = 1;
	while (p < argc)
	{
		if (is_num(argv[p]))
		{
			push_to_back(&stack_a, ft_atoi(argv[p]));
		}
		else
		{
			return (0);
		}
		p += 1;
	}
	print_stack(stack_a);
	sort(&stack_a, p)
	//	swap_a(stack);
//	while (stack_a)
//	{
//		push_ab(&stack_b, &stack_a);
//		printf("b:\n");
//		print_stack(stack_b);
//		printf("a:\n");
//		print_stack(stack_a);
//	}
//	rotate_down(&stack_a);
//	print_stack(stack_a);
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
