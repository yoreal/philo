/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlalisse <mlalisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 12:50:14 by mlalisse          #+#    #+#             */
/*   Updated: 2013/12/22 19:42:55 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "./printf/includes/ft_printf.h"

int		kprintf(char *format, ...)
{
	int		i;
	va_list vl;

	va_start(vl, format);
	i = vprintf(format, vl); // stdio.h
	va_end(vl);
	fflush(stdout);
	return(i);
}

#define kassert(t) assert(t); fflush(stdout);
#define test_printf(fmt, ...) kprintf("-> %s", fmt); kassert( kprintf(fmt, ##__VA_ARGS__) == ft_printf(fmt, ##__VA_ARGS__) );

int		g = 1;

int		main()
{
	int		i = 1;

	kprintf("-- -- %%d -- --\n");
	test_printf("%d\n", 18);
	test_printf("%d\n", -18);
	test_printf("%d\n", 2387);
	test_printf("%d\n", -2387);
	test_printf("%d\n", 2147483647);
	test_printf("%d\n", -2147483648);

	kprintf("-- -- %%+d -- --\n");
	test_printf("%+d\n", -18);
	test_printf("%+d\n", 2387);
	test_printf("%+d\n", -2387);
	test_printf("%+d\n", 0);

	kprintf("-- -- %%+ d -- --\n");
	test_printf("%+ d\n", -18);
	test_printf("%+ d\n", 2387);
	test_printf("%+ d\n", -2387);
	test_printf("%+ d\n", 0);

	kprintf("-- -- %%3d -- --\n");
	test_printf("%3d\n", -18);
	test_printf("%3d\n", 2387);
	test_printf("%3d\n", -2387);
	test_printf("%3d\n", 0);

	kprintf("-- -- %%-3d -- --\n");
	test_printf("%-3d\n", -18);
	test_printf("%-3d\n", 2387);
	test_printf("%-3d\n", -2387);
	test_printf("%-3d\n", 0);
	test_printf("%-d\n", 2147483647);
	test_printf("%-d\n", -2147483648);
	test_printf("%-15d\n", 2147483647);
	test_printf("%-15d\n", -2147483648);

	kprintf("-- -- %%.3d -- --\n");
	test_printf("%.3d\n", -18);
	test_printf("%.3d\n", 2387);
	test_printf("%.3d\n", -2387);
	test_printf("%.3d\n", 0);

	kprintf("-- -- %%3*d -- --\n");
	test_printf("%3*d\n", 0, 18);
	test_printf("%3*d\n", 2, 18);
	test_printf("%3*d\n", 3, 18);
	test_printf("%3*d\n", 6, 18);
	test_printf("%3*d\n", 0, -18);
	test_printf("%3*d\n", 2, -18);
	test_printf("%3*d\n", 6, -18);
	test_printf("%3*d\n", 2, 2387);
	test_printf("%2*d\n", 8, 2387);

	//test_printf("%6c\n", 'a');
	//test_printf("%-6c$\n", 'a');
	kprintf("-- -- %%c -- --\n");
	test_printf("%c\n", 'a');
	test_printf("%c\n", 'A');
	test_printf("%c\n", -'a');
	test_printf("%c\n", 127);
	test_printf("%c\n", -128);
	test_printf("%c\n", 0);
	kprintf("-- -- %%3c -- --\n");
	test_printf("%3c\n", 'a');
	test_printf("%3c\n", 'A');
	test_printf("%3c\n", -'a');
	test_printf("%3c\n", 127);
	test_printf("%3c\n", -128);
	test_printf("%3c\n", 0);
	kprintf("-- -- %%-3c -- --\n");
	test_printf("%-3c\n", 'a');
	test_printf("%-3c\n", 'A');
	test_printf("%-3c\n", -'a');
	test_printf("%-3c\n", 127);
	test_printf("%-3c\n", -128);
	test_printf("%-3c\n", 0);
	kprintf("-- -- %%*c -- --\n");
	test_printf("%*c\n", 0, 'a');
	test_printf("%*c\n", 1, 'a');
	test_printf("%*c\n", 3, 'a');
	test_printf("%*c\n", 4, 'a');
	test_printf("%*c\n", -1, 'a');
	test_printf("%*c\n", -3, 'a');
	test_printf("%*c\n", -4, 'a');
	test_printf("%*c\n", 0, 127);
	test_printf("%*c\n", 1, 127);
	test_printf("%*c\n", 5, 127);
	test_printf("%*c\n", -5, 127);
	test_printf("%*c\n", 0, 0);
	test_printf("%*c\n", 1, 0);
	test_printf("%*c\n", 5, 0);
	test_printf("%*c\n", -5, 0);
	kprintf("-- -- %%.*c -- --\n");
	test_printf("%.*c\n", 0, 'a');
	test_printf("%.*c\n", 1, 'a');
	test_printf("%.*c\n", 3, 'a');
	test_printf("%.*c\n", 4, 'a');
	test_printf("%.*c\n", -1, 'a');
	test_printf("%.*c\n", -3, 'a');
	test_printf("%.*c\n", -4, 'a');
	test_printf("%.*c\n", 0, 127);
	test_printf("%.*c\n", 1, 127);
	test_printf("%.*c\n", 5, 127);
	test_printf("%.*c\n", -5, 127);
	test_printf("%.*c\n", 0, 0);
	test_printf("%.*c\n", 1, 0);
	test_printf("%.*c\n", 5, 0);
	test_printf("%.*c\n", -5, 0);
	printf("-- -- %%d -- --\n");
	test_printf("%d\n", 1);
	test_printf("%d\n", 5);
	test_printf("%d\n", -5);
	printf("-- -- %%.d -- --\n");
	test_printf("%.d\n", 0);
	test_printf("%.d\n", 5);
	test_printf("%.d\n", -5);
	printf("-- -- %%.*d -- --\n");
	test_printf("%.*d\n", 0, 5);
	test_printf("%.*d\n", 0, -5);
	test_printf("%.*d\n", 5, 0);
	test_printf("%.*d\n", 5, -5);
	test_printf("%.*d\n", -5, 0);
	test_printf("%.*d\n", -5, -5);
	printf("-- -- %%.s -- --\n");
	test_printf("%.s\n","Hello");
	test_printf("%.1s\n","Hello");
	test_printf("%.2s\n", "Hello");
	test_printf("%.0s\n", "Hello");
	test_printf("%.10s\n", "Hello");
	printf("-- -- %%u -- --\n");
	test_printf("%2.2u\n", 5);
	test_printf("%2.1u\n", 5);
	test_printf("%2.3u\n", 5);
	test_printf("%3.2u\n", 5);
	test_printf("%5.0u\n", 5);
	test_printf("%0.2u\n", 5);
	test_printf("%3.7u\n", 5);
	test_printf("%7.3u\n", 5);
	printf("-- -- -- --\n");
	test_printf("%3.2s\n", "Hello world");
	test_printf("%1.1s\n", "Hello world");
	test_printf("%4.3s\n", "Hello world");
	test_printf("%.2s\n", "Hello world");
	test_printf("%s\n", "Hello world");
	test_printf("%.2s\n", "Hello world");
	test_printf("%.7s\n", "Hello world");
	test_printf("%.3s\n", "Hello world");
	test_printf("% s\n", NULL);
	test_printf("% 3s\n", NULL);
	test_printf("% s\n", "Hello world");
	test_printf("% 2s\n", "Hello world");
	test_printf("% 7s\n", "Hello world");
	printf("-- -- -- --\n");
	test_printf("%2.2d\n", 5);
	test_printf("%2.1d\n", 5);
	test_printf("%2.3d\n", 5);
	test_printf("%3.2d\n", 5);
	test_printf("%5.0d\n", 5);
	test_printf("%0.2d\n", 5);
	test_printf("%3.7d\n", 5);
	test_printf("%7.3d\n", 5);
	printf("-- -- -- --\n");
	test_printf("%2.2d\n", 0);
	test_printf("%2.1d\n", 0);
	test_printf("%2.3d\n", 0);
	test_printf("%3.2d\n", 0);
	test_printf("%5.0d$\n", 0);
	test_printf("%0.2d\n", 0);
	test_printf("%3.7d\n", 0);
	test_printf("%7.3d\n", 0);
	printf("-- -- -- --\n");
	test_printf("%2.2d\n", -5);
	test_printf("%2.1d\n", -5);
	test_printf("%2.3d\n", -5);
	test_printf("%3.2d\n", -5);
	test_printf("%5.0d\n", -5);
	test_printf("%0.2d\n", -5);
	test_printf("%3.7d\n", -5);
	test_printf("%7.3d\n", -5);
	printf("-- -- -- --\n");
	test_printf("%2.6d\n", -346);
	test_printf("%7.1d\n", -346);
	test_printf("%5.3d\n", -346);
	test_printf("%6.2d\n", -346);
	test_printf("%8.0d\n", -346);
	test_printf("%0.8d\n", -346);
	test_printf("%3.7d\n", -346);
	test_printf("%7.3d\n", -346);
	printf("-- -- -- --\n");
	test_printf("%2.6d\n", 346);
	test_printf("%7.1d\n", 346);
	test_printf("%5.3d\n", 346);
	test_printf("%6.2d\n", 346);
	test_printf("%8.0d\n", 346);
	test_printf("%0.8d\n", 346);
	test_printf("%3.7d\n", 346);
	test_printf("%7.3d\n", 346);
	printf("-- -- -- --\n");
	// star
	test_printf("%*d$\n", 6, -2356);
	test_printf("% *d$\n", 7, -3455);
	test_printf("%*d$\n", 0, 3455);
	test_printf("%*d$\n", -1, 3455);
	test_printf("%*d$\n", -10, 3455);
	//ft_printf("%*d\n", 2147483648, 3455);
	//printf("%*d\n", 2147483648, 3455);

	// flags
	test_printf("%06d\n", -2356);
	test_printf("% 6d\n", -3455);
	test_printf("%-6d\n", -3455);
	test_printf("%-+6d\n", -455);
	test_printf("%-+6d\n", 455);
	test_printf("%- 6d$\n", 455);
	test_printf("% -6d$\n", -455);

	printf("-- -- %%*d -- --\n");
	test_printf("%*d\n", 0, 0);
	test_printf("%*d\n", 1, 10);
	test_printf("%*d\n", 10, 0);
	test_printf("%*d\n", 10, 10);
	test_printf("%*d\n", -10, 10);

	printf("-- -- %%03*d -- --\n");
	test_printf("%03*d\n", 0, 0);
	test_printf("%03*d\n", 1, 10);
	test_printf("%03*d\n", 10, 0);
	test_printf("%03*d\n", 10, 10);
	test_printf("%03*d\n", -10, 10);

	// %%
	printf("-- -- %%%% -- --\n");
	test_printf("%%\n");
	test_printf("%Z\n");
	test_printf("%2%\n");
	test_printf("%2Z\n");
	test_printf("%5%\n");
	test_printf("%5Z\n");
	printf("-- -- %%3%% -- --\n");
	test_printf("%0%\n");
	test_printf("%0Z\n");
	test_printf("%2%\n");
	test_printf("%2Z\n");
	test_printf("%5%\n");
	test_printf("%5Z\n");
	printf("-- -- %%-3%% -- --\n");
	test_printf("%-0%\n");
	test_printf("%-0Z\n");
	test_printf("%-2%\n");
	test_printf("%-2Z\n");
	test_printf("%-5%\n");
	test_printf("%-5Z\n");
	printf("-- -- %%.%% -- --\n");
	test_printf("%.%\n");
	test_printf("%.Z\n");
	test_printf("%.2%\n");
	test_printf("%.3%\n");
	test_printf("%.5%\n");
	test_printf("%.2Z\n");
	test_printf("%.3Z\n");
	test_printf("%.5Z\n");

	// %x, %X
	printf("-- -- %%x -- --\n");
	test_printf("%x\n", 512);
	test_printf("%x\n", 18);
	test_printf("%x\n", -512);
	test_printf("%x\n", -18);
	test_printf("%x\n", 0);
	printf("-- -- %%X -- --\n");
	test_printf("%X\n", 512);
	test_printf("%X\n", 18);
	test_printf("%X\n", -512);
	test_printf("%X\n", -18);
	test_printf("%X\n", 0);
	printf("-- -- %%.x -- --\n");
	test_printf("%2x\n", 0);
	test_printf("%3x\n", 0);
	test_printf("%2x\n", 10);
	test_printf("%3x\n", 10);
	printf("-- -- %%.X -- --\n");
	test_printf("%2X\n", 0);
	test_printf("%3X\n", 0);
	test_printf("%2X\n", 10);
	test_printf("%3X\n", 10);
	printf("-- -- %%.x -- --\n");
	test_printf("%.2x\n", 0);
	test_printf("%.3x\n", 0);
	test_printf("%.3x\n", 0);
	test_printf("%.2x\n", 10);
	test_printf("%.3x\n", 10);
	test_printf("%.3x\n", 10);
	printf("-- -- %%.X -- --\n");
	test_printf("%.2x\n", 0);
	test_printf("%.3X\n", 0);
	test_printf("%.3X\n", 0);
	test_printf("%.2X\n", 10);
	test_printf("%.3X\n", 10);
	test_printf("%.3X\n", 10);
	printf("-- -- %%#x -- --\n");
	test_printf("%#x\n", 0);
	test_printf("%#x\n", 1);
	test_printf("%#x\n", -1);
	test_printf("%#x\n", 16);
	test_printf("%#x\n", 455);
	test_printf("%#x\n", -455);
	printf("-- -- %%#x -- --\n");
	test_printf("%#x\n", 0);
	test_printf("%#x\n", 1);
	test_printf("%#x\n", -1);
	test_printf("%#x\n", 16);
	test_printf("%#x\n", 455);
	test_printf("%#x\n", -455);
	test_printf("%#3x\n", 0);
	test_printf("%#3x\n", 1);
	test_printf("%#3x\n", -1);
	test_printf("%#3x\n", 16);
	test_printf("%#3x\n", 455);
	test_printf("%#10x\n", -455);
	test_printf("%#.3x\n", 0);
	test_printf("%#.3x\n", 1);
	test_printf("%#.3x\n", -1);
	test_printf("%#.3x\n", 16);
	test_printf("%#.3x\n", 455);
	test_printf("%#.10x\n", -455);
	test_printf("%#1.3x\n", 0);
	test_printf("%#3.1x\n", 0);
	test_printf("%#0.3x\n", 0);
	test_printf("%#1.3x\n", 1);
	test_printf("%#3.1x\n", 1);
	test_printf("%#1.x\n", -1);
	test_printf("%#3.x\n", -1);
	test_printf("%#.1x\n", -1);
	test_printf("%#.3x\n", -1);
	test_printf("%#1.3x\n", 44444);
	test_printf("%#3.1x\n", 44444);
	test_printf("%#1.x\n", -44444);
	test_printf("%#3.x\n", -44444);
	test_printf("%#.1x\n", -44444);
	test_printf("%#.3x\n", -44444);
	printf("-- -- %%#X -- --\n");
	//test_printf("%#X\n", 0);
	test_printf("%#X\n", 1);
	test_printf("%#X\n", -1);
	test_printf("%#X\n", 16);
	test_printf("%#X\n", 455);
	test_printf("%#X\n", -455);
	test_printf("%#3X\n", 0);
	test_printf("%#3X\n", 1);
	test_printf("%#3X\n", -1);
	test_printf("%#3X\n", 16);
	test_printf("%#3X\n", 455);
	test_printf("%#10X\n", -455);
	test_printf("%#.3X\n", 0);
	test_printf("%#.3X\n", 1);
	test_printf("%#.3X\n", -1);
	test_printf("%#.3X\n", 16);
	test_printf("%#.3X\n", 455);
	test_printf("%#.10X\n", -455);
	test_printf("%#1.3X\n", 0);
	test_printf("%#3.1X\n", 0);
	test_printf("%#0.3X\n", 0);
	test_printf("%#1.3X\n", 1);
	test_printf("%#3.1X\n", 1);
	test_printf("%#1.X\n", -1);
	test_printf("%#3.X\n", -1);
	test_printf("%#.1X\n", -1);
	test_printf("%#.3X\n", -1);
	test_printf("%#1.3X\n", 44444);
	test_printf("%#3.1X\n", 44444);
	test_printf("%#1.X\n", -44444);
	test_printf("%#3.X\n", -44444);
	test_printf("%#.1X\n", -44444);
	test_printf("%#.3X\n", -44444);

	// %p
	printf("-- -- %%3p -- --\n");
	test_printf("%3p\n", (void*) 0);
	test_printf("%3p\n", (void*) 1);
	test_printf("%3p\n", (void*) -1);
	test_printf("%3p\n", (void*) 16);
	test_printf("%3p\n", (void*) 455);
	printf("-- -- %%10p -- --\n");
	test_printf("%10p\n", (void*) -455);
	test_printf("%10p\n", (void*) 0);
	test_printf("%10p\n", (void*) 1);
	test_printf("%10p\n", (void*) -1);
	test_printf("%10p\n", (void*) 16);
	test_printf("%10p\n", (void*) 455);
	test_printf("%10p\n", (void*) -455);
	printf("-- -- %%.p -- --\n");
	test_printf("%.p\n", (void*) 0);
	test_printf("%.p\n", (void*) 1);
	test_printf("%.p\n", (void*) -1);
	test_printf("%.p\n", (void*) 16);
	test_printf("%.p\n", (void*) 455);
	test_printf("%.p\n", (void*) -455);
	test_printf("%.1p\n", (void*) 0);
	test_printf("%.1p\n", (void*) 1);
	test_printf("%.1p\n", (void*) -1);
	test_printf("%.1p\n", (void*) 16);
	test_printf("%.1p\n", (void*) 455);
	test_printf("%.1p\n", (void*) -455);
	test_printf("%.3p\n", (void*) 0);
	test_printf("%.3p\n", (void*) 1);
	test_printf("%.3p\n", (void*) -1);
	test_printf("%.3p\n", (void*) 16);
	test_printf("%.3p\n", (void*) 455);
	test_printf("%.3p\n", (void*) -455);
	test_printf("%.10p\n", (void*) -455);
	test_printf("%.20p\n", (void*) -455);
	printf("-- -- %%3.p -- --\n");
	test_printf("%3.p\n", (void*) 0);
	test_printf("%3.p\n", (void*) 1);
	test_printf("%3.p\n", (void*) -1);
	test_printf("%3.p\n", (void*) 16);
	test_printf("%3.p\n", (void*) 455);
	test_printf("%3.p\n", (void*) -455);
	printf("-- -- %%3.1p -- --\n");
	test_printf("%3.1p\n", (void*) 0);
	test_printf("%3.1p\n", (void*) 1);
	test_printf("%3.1p\n", (void*) -1);
	test_printf("%3.1p\n", (void*) 16);
	test_printf("%3.1p\n", (void*) 455);
	test_printf("%3.1p\n", (void*) -455);
	printf("-- -- %%3.3p -- --\n");
	test_printf("%3.3p\n", (void*) 0);
	test_printf("%3.3p\n", (void*) 1);
	test_printf("%3.3p\n", (void*) -1);
	test_printf("%3.3p\n", (void*) 16);
	test_printf("%3.3p\n", (void*) 455);
	test_printf("%3.3p\n", (void*) -455);
	test_printf("%3.10p\n", (void*) -455);
	test_printf("%3.20p\n", (void*) -455);
	printf("-- -- %%#p -- --\n");
	test_printf("%#.p\n", (void*) 0);
	test_printf("%#.p\n", (void*) 1);
	test_printf("%#.p\n", (void*) -1);
	test_printf("%#.p\n", (void*) 16);
	test_printf("%#.p\n", (void*) 455);
	test_printf("%#.p\n", (void*) -455);
	test_printf("%#.4p\n", (void*) 0);
	test_printf("%#.4p\n", (void*) 1);
	test_printf("%#.4p\n", (void*) -1);
	test_printf("%#.4p\n", (void*) 16);
	test_printf("%#.4p\n", (void*) 455);
	test_printf("%#.4p\n", (void*) -455);
	test_printf("%#4p\n", (void*) 0);
	test_printf("%#4p\n", (void*) 1);
	test_printf("%#4p\n", (void*) -1);
	test_printf("%#4p\n", (void*) 16);
	test_printf("%#4p\n", (void*) 455);
	test_printf("%#4.4p\n", (void*) -455);
	test_printf("%#4.4p\n", (void*) 0);
	test_printf("%#4.4p\n", (void*) 1);
	test_printf("%#4.4p\n", (void*) -1);
	test_printf("%#4.4p\n", (void*) 16);
	test_printf("%#4.4p\n", (void*) 455);
	test_printf("%#4.4p\n", (void*) -455);

	// %o
	printf("-- -- %%o -- --\n");
	test_printf("%o\n", -512);
	test_printf("%o\n", -18);
	printf("-- -- %%#o -- --\n");
	test_printf("%#o\n", 0);
	test_printf("%#o\n", 1);
	test_printf("%#o\n", -1);
	test_printf("%#o\n", 455);
	test_printf("%#o\n", -455);

	test_printf("%d\n", -18);
	test_printf("%d\n", -2387);
	test_printf("%u\n", -18);
	test_printf("%u\n", -2387);
	test_printf("%u\n", 0);
	test_printf("%s\n", NULL);
	test_printf("%s%s\n", "Yo", " man");
	test_printf("%s\n", "");
	test_printf("%s\n", "abcdefghijklmnopqrtuvwxyz");
	test_printf("%p\n", &i);
	test_printf("%p\n", &g);
	test_printf("% d\n", -18);
	test_printf("% d\n", 2387);
	test_printf("% d\n", -2387);
	test_printf("% d\n", 2147483647);

	test_printf("%03%\n");
	test_printf("%010p\n", 1);
	test_printf("%+03d\n", 1);
	test_printf("% 03d\n", 1);
	test_printf("% 03d\n", 1);
	test_printf("%0-10d\n", 10);

	printf("-- -- %%03*c -- --\n");
	test_printf("%03*c\n", 0, 0);
	test_printf("%03*c\n", 1, 8);
	test_printf("%03*c\n", 10, 0);
	test_printf("%03*c\n", 10, 8);
	test_printf("%03*c\n", -10, 8);
	test_printf("%03*c\n", 0, 'a');
	test_printf("%03*c\n", 1, 'a');
	test_printf("%03*c\n", 10, 'a');
	test_printf("%03*c\n", 10, 'a');
	test_printf("%03*c\n", -10, 'a');

	printf("-- -- %%03*d -- --\n");
	test_printf("%03*d\n", 0, 0);
	test_printf("%03*d\n", 1, 8);
	test_printf("%03*d\n", 10, 0);
	test_printf("%03*d\n", 10, 8);
	test_printf("%03*d\n", -10, 8);
	test_printf("%03*d\n", 0, 'a');
	test_printf("%03*d\n", 1, 'a');
	test_printf("%03*d\n", 10, 'a');
	test_printf("%03*d\n", 10, 'a');
	test_printf("%03*d\n", -10, 'a');

	printf("-- -- %%03*.d -- --\n");
	test_printf("%03*.d\n", 0, 8888);
	test_printf("%03*.d\n", 1, 8888);
	test_printf("%03*.d\n", 4, 8888);
	test_printf("%03*.d\n", 5, 8888);
	test_printf("%03*.d\n", 10, 8888);
	test_printf("%03*.d\n", 0, 8888);
	test_printf("%03*.d\n", -1, 8888);
	test_printf("%03*.d\n", -4, 8888);
	test_printf("%03*.d\n", -5, 8888);
	test_printf("%03*.d\n", -10, 8888);

	printf("-- -- %%03d -- --\n");
	test_printf("%03d\n", 0);
	test_printf("%03d\n", 1);
	test_printf("%03d\n", 4);
	test_printf("%03d\n", 0);
	test_printf("%03d\n", 1);
	test_printf("%03d\n", 4);
	test_printf("%03d\n", -1);
	test_printf("%03d\n", -4);

	printf("-- -- %%03.d -- --\n");
	test_printf("%03.d\n", 0);
	test_printf("%03.d\n", 1);
	test_printf("%03.d\n", 4);
	test_printf("%03.d\n", 0);
	test_printf("%03.d\n", 1);
	test_printf("%03.d\n", 4);
	test_printf("%03.d\n", -1);
	test_printf("%03.d\n", -4);

	printf("-- -- %%03.4d -- --\n");
	test_printf("%03.4d\n", 0);
	test_printf("%03.4d\n", 4);
	test_printf("%03.4d\n", 100);
	test_printf("%03.4d\n", 1000);
	test_printf("%03.4d\n", -4);
	test_printf("%03.4d\n", -100);
	test_printf("%03.4d\n", -1000);

	printf("-- -- %%03x -- --\n");
	test_printf("%03x\n", 0);
	test_printf("%03x\n", 4);
	test_printf("%03x\n", 100);
	test_printf("%03x\n", 1000);
	test_printf("%03x\n", -4);
	test_printf("%03x\n", -100);
	test_printf("%03x\n", -1000);

	printf("-- -- %%03.x -- --\n");
	test_printf("%03.x\n", 0);
	test_printf("%03.x\n", 4);
	test_printf("%03.x\n", 100);
	test_printf("%03.x\n", 1000);
	test_printf("%03.x\n", -4);
	test_printf("%03.x\n", -100);
	test_printf("%03.x\n", -1000);

	printf("-- -- %%03.4x -- --\n");
	test_printf("%03.4x\n", 0);
	test_printf("%03.4x\n", 4);
	test_printf("%03.4x\n", 100);
	test_printf("%03.4x\n", 1000);
	test_printf("%03.4x\n", -4);
	test_printf("%03.4x\n", -100);
	test_printf("%03.4x\n", -1000);

	printf("-- -- %%03*.3d -- --\n");
	test_printf("%03*.3d\n", 0, 0);
	test_printf("%03*.3d\n", 0, 10);
	test_printf("%03*.3d\n", 0, 100);
	test_printf("%03*.3d\n", 1, 0);
	test_printf("%03*.3d\n", 1, 10);
	test_printf("%03*.3d\n", 1, 100);
	test_printf("%03*.3d\n", 3, 0);
	test_printf("%03*.3d\n", 3, 10);
	test_printf("%03*.3d\n", 3, 100);
	test_printf("%03*.3d\n", 5, 0);
	test_printf("%03*.3d\n", 5, 10);
	test_printf("%03*.3d\n", 5, 100);

	printf("-- -- %%c -- --\n");
	test_printf("%c\n", 0);
	test_printf("%c\n", 'a');
	test_printf("%c\n", '0');

	printf("-- -- %%03.3c -- --\n");
	test_printf("%.0c\n", '0');
	test_printf("%.3c\n", '0');
	test_printf("%.7c\n", '0');

	printf("-- -- %%3.3c -- --\n");
	test_printf("%0.3c\n", '0');
	test_printf("%1.3c\n", '0');
	test_printf("%3.3c\n", '0');
	test_printf("%5.3c\n", '0');

	printf("-- -- %%03.3c -- --\n");
	test_printf("%00.3c\n", '0');
	test_printf("%01.3c\n", '0');
	test_printf("%03.3c\n", '0');
	test_printf("%05.3c\n", '0');

	printf("-- -- %%3*.3c -- --\n");
	test_printf("%3*.3c\n", 0, '0');
	test_printf("%3*.3c\n", 1, '0');
	test_printf("%3*.3c\n", 3, '0');
	test_printf("%3*.3c\n", 5, '0');
	test_printf("%3*.3c\n", 0, 0);
	test_printf("%3*.3c\n", 1, 0);
	test_printf("%3*.3c\n", 3, 0);
	test_printf("%3*.3c\n", 5, 0);

	printf("-- -- %%03*.3c -- --\n");
	test_printf("%03*.3c\n", 0, '0');
	test_printf("%03*.3c\n", 1, '0');
	test_printf("%03*.3c\n", 3, '0');
	test_printf("%03*.3c\n", 5, '0');
	test_printf("%03*.3c\n", 0, 0);
	test_printf("%03*.3c\n", 1, 0);
	test_printf("%03*.3c\n", 3, 0);
	test_printf("%03*.3c\n", 5, 0);

	printf("-- -- %%03*.3c -- --\n");
	test_printf("%03*.s\n", 0, "Hey man");
	test_printf("%03*.s\n", 1, "Hey man");
	test_printf("%03*.s\n", 3, "Hey man");
	test_printf("%03*.s\n", 5, "Hey man");
	test_printf("%03*.s\n", 0, "Hey man");
	test_printf("%03*.s\n", 1, "Hey man");
	test_printf("%03*.s\n", 3, "Hey man");
	test_printf("%03*.s\n", 5, "Hey man");

	printf("-- -- %%03*.p -- --\n");
	test_printf("%03*.p\n", 0, "Hey man");
	test_printf("%03*.p\n", 1, "Hey man");
	test_printf("%03*.p\n", 3, "Hey man");
	test_printf("%03*.p\n", 20, "Hey man");
	test_printf("%03*.p\n", 0, "Hey man");
	test_printf("%03*.p\n", 1, "Hey man");
	test_printf("%03*.p\n", 3, "Hey man");
	test_printf("%03*.p\n", 20, "Hey man");

	printf("-- -- %%03*.%% -- --\n");
	test_printf("%03*.%\n", 0);
	test_printf("%03*.%\n", 1);
	test_printf("%03*.%\n", 2);
	test_printf("%03*.%\n", 5);
	test_printf("%03*.%\n", -1);
	test_printf("%03*.%\n", -2);
	test_printf("%03*.%\n", -5);

	printf("-- -- %%03*.u -- --\n");
	test_printf("%03.u\n", 0);
	test_printf("%03.u\n", 1);
	test_printf("%03.u\n", 2);
	test_printf("%03.u\n", 5);
	test_printf("%03.u\n", -1);
	test_printf("%013.u\n", -2);

	printf("-- -- %%03*.X -- --\n");
	test_printf("%03.X\n", 84840);
	test_printf("%03.X\n", 14884);
	test_printf("%03.X\n", 0xafdb2);


	printf("-- -- %%+03*.d -- --\n");
	test_printf("%+03*.d\n", 84, 84);
	test_printf("%+03*.d\n", 8, 84);
	test_printf("%+03*.d\n", -8, 84);
	test_printf("%+03*.d\n", -8, -84);

	printf("-- -- %%#-+03o -- --\n");
	test_printf("%#-+03o\n", 84);
	test_printf("%#-+03o\n", 1);
	test_printf("%#-+03o\n", 0);

	printf("-- -- %%#-+03d -- --\n");
	test_printf("%#-+03x\n", 84);
	test_printf("%#-+03x\n", 1);
	test_printf("%#-+03x\n", 0);

	printf("-- -- %%03p -- --\n");
	test_printf("%#03p\n", NULL);
	test_printf("%#03p\n", &i);
	test_printf("%#03p\n", &g);

	printf("-- -- %%#.10o -- --\n");
	test_printf("%#.10o\n", 0, 0);
	test_printf("%#.10o\n", 0, 10);
	test_printf("%#.10o\n", 0, -1);
	test_printf("%#.10o\n", 8, 0);
	test_printf("%#.10o\n", 8, 10);
	test_printf("%#.10o\n", 8, -1);

	printf("-- -- %%.10o -- --\n");
	test_printf("%.10o\n", 0, 0);
	test_printf("%.10o\n", 0, 10);
	test_printf("%.10o\n", 0, -1);
	test_printf("%.10o\n", 8, 0);
	test_printf("%.10o\n", 8, 10);
	test_printf("%.10o\n", 8, -1);

	printf("-- -- %%#-+03*.10o -- --\n");
	test_printf("%#-+03*.10o\n", 0, 0);
	test_printf("%#-+03*.10o\n", 0, 10);
	test_printf("%#-+03*.10o\n", 0, -1);
	test_printf("%#-+03*.10o\n", 8, 0);
	test_printf("%#-+03*.10o\n", 8, 10);
	test_printf("%#-+03*.10o\n", 8, -1);

	printf("-- -- %%#-+03*.x -- --\n");
	test_printf("%#-+03*.x\n", 0, 0);
	test_printf("%#-+03*.x\n", 0, 1);
	test_printf("%#-+03*.x\n", 0, 6);
	test_printf("%#-+03*.x\n", 8, 0);
	test_printf("%#-+03*.x\n", 8, 1);
	test_printf("%#-+03*.x\n", 8, 6);
	test_printf("%#-+03*.x\n", -8, 0);
	test_printf("%#-+03*.x\n", -8, 1);
	test_printf("%#-+03*.x\n", -8, 6);

	printf("-- -- %%#-+03*.X -- --\n");
	test_printf("%#-+03*.X\n", 0, 0);
	test_printf("%#-+03*.X\n", 0, 1);
	test_printf("%#-+03*.X\n", 0, 6);
	test_printf("%#-+03*.X\n", 8, 0);
	test_printf("%#-+03*.X\n", 8, 1);
	test_printf("%#-+03*.X\n", 8, 6);
	test_printf("%#-+03*.X\n", -8, 0);
	test_printf("%#-+03*.X\n", -8, 1);
	test_printf("%#-+03*.X\n", -8, 6);

	printf("-- -- %%#-+03*.o -- --\n");
	test_printf("%#-+03*.o\n", 0, 0);
	test_printf("%#-+03*.o\n", 0, 1);
	test_printf("%#-+03*.o\n", 0, 6);
	test_printf("%#-+03*.o\n", 8, 0);
	test_printf("%#-+03*.o\n", 8, 1);
	test_printf("%#-+03*.o\n", 8, 6);
	test_printf("%#-+03*.o\n", -8, 0);
	test_printf("%#-+03*.o\n", -8, 1);
	test_printf("%#-+03*.o\n", -8, 6);

	printf("-- -- %%#-+03*.p -- --\n");
	test_printf("%#-+03*.p\n", 0, 0);
	test_printf("%#-+03*.p\n", 0, 1);
	test_printf("%#-+03*.p\n", 0, 6);
	test_printf("%#-+03*.p\n", 8, 0);
	test_printf("%#-+03*.p\n", 8, 1);
	test_printf("%#-+03*.p\n", 8, 6);
	test_printf("%#-+03*.p\n", -8, 0);
	test_printf("%#-+03*.p\n", -8, 1);
	test_printf("%#-+03*.p\n", -8, 6);

	return (0);
}
