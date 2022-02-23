/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi     <abambi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:08:40 by abambi            #+#    #+#             */
/*   Updated: 2021/03/30 19:08:45 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# ifdef LINUX
#  define SYSTEM_NAME 1
# endif

# ifdef MACOS
#  define SYSTEM_NAME 2
# endif

# define M_PI 3.14159265358979323846
# define EPSILON 0.00001
# define ALBEDO 0.3

/*
** # define NOEVENTMASK     0L
** # define KEYPRESSMASK    (1L<<0)
** # define KEYRELEASEMASK  (1L<<1)
*/

# define KEYPRESS 2
# define KEYRELEASE 3

# ifdef LINUX
#  define SP_KEY 32
# else
#  define SP_KEY 49
# endif

# ifdef MACOS
#  define ESC_KEY 53
# else
#  define ESC_KEY 65307
# endif

#endif
