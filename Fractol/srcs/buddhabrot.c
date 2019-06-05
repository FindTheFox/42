/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:34:46 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/05 04:59:47 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    *buddhabrot_thread(void *thread)
{
    t_fractol   f;
    t_thread    *t;
    t_env       *e;

    e = ((t_thread*)thread)->e;
    e->f = &f;
    t = (t_thread*)thread;
    t->start = t->n * WIDTH / THREADS;
    t->end = (t->n + 1) * WIDTH / THREADS;
    f.i.x = t->start;
    while(f.i.x < t->end)
    {
        f.i.y = -1;
        while(++f.i.y < HEIGHT)
        {
            buddhabrot(&f, e);
            //e->data[(int)f.i.x][(int)f.i.y] = (t_pixel){.c.real = f.z_r, .c.imag = f.z_i,
            // .i = f.iter};
        }
        f.i.x++; 
    }
    pthread_exit(NULL);
    return (NULL);
}

void            buddhabrot(t_fractol *f, t_env *e)
{
            t_rng   t;
            double  n;
            
            f->c_r = (f->i.x / e->zoom) + e->x1 + e->offset.x;
            f->c_i = (f->i.y / e->zoom) + e->y1 + e->offset.y;
            f->z_r = 0;
            f->z_i = 0;
            f->iter = 0;
		    n = f->z_r * f->z_r + f->z_i * f->z_i; 
            while(n < 3.1 && f->iter < e->max_iter)
            {   
                f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
                f->z_i = 2 * f->z_i * f->z_r + f->c_i;
                f->z_r = f->tmp;
                f->iter++;
                n = f->z_r * f->z_r + f->z_i * f->z_i;
            
				//printf("iter1 = %d\n", f->iter);

            }
			if (f->iter > 20 && f->iter < e->max_iter)
			{
				f->iter = 0;
				f->z_r = 0;
				f->z_i = 0;
                n = f->z_r * f->z_r + f->z_i * f->z_i; 
				while (n < 3.1 && f->iter < e->max_iter)
				{
					//printf("iter2 = %d\n", f->iter);
                    f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
                    f->z_i = 2 * f->z_i * f->z_r + f->c_i;
                    f->z_r = f->tmp;
                    f->iter++;
                    n = f->z_r * f->z_r + f->z_i * f->z_i;
				    f->iter++;
					t.imag = (int)((f->z_r - e->x1) * e->zoom);
					t.real = (int)((f->z_i - e->y1) * e->zoom);
					if ((t.real < WIDTH && t.real >= 0)
						&& (t.imag < HEIGHT && t.imag >= 0))
                        e->img[(int)(t.real * WIDTH + t.imag)] += buddhabrot_color(e, f);//e->cycle * 255;   
                }
            }
}

int         buddhabrot_color(t_env *e, t_fractol *f)
{
    t_color color;
	//double	nu;
	double	nu_frac;
	//double 	mult;

	//mult = f->z_r * f->z_r + f->z_i * f->z_i;
	//nu = (f->iter + e->cycle - log2(log2(sqrt(mult)))) / e->max_iter;
	//nu_frac = nu - (int)nu;
	nu_frac = f->iter / e->cycle;
    color.rgb.r = (nu_frac * 5) * e->r;
	color.rgb.g = (255 - (nu_frac * 10)) * e->g;
	color.rgb.b = (255 - (nu_frac * 2)) * e->b;
	color.value = color.rgb.r << 16 | color.rgb.g << 8 | color.rgb.b;
	return (color.value);
}