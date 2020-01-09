/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 18:41:12 by rstarfir          #+#    #+#             */
/*   Updated: 2019/12/08 21:34:46 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 1.get the representation of the floating point number as a fraction of 2
** that are 0 < frac < 10
** 		1.1 represent the float.point number as a pair of integers in the equation
**			val_mantissa * 2 ^ val_exponent
**			init val_matissa & val_exponent:
**				for 64-bit(double):
**				denormalized: val_matissa = mantissa * 2 ^ (1-1023-52)
**				normalized: val_mantissa = (mantissa * 2 ^ 52) * 2 (exponent - 1023)
**
**				for 80-bit(long double):
**				denormalized: val_mantissa = mantissa * 2 ^ (1-16383-63)
**				normalized: val_mantissa = (mantissa * 2 ^ 63) * 2 (exponent - 16383)
**		
**		1.2   Then, represent it as a fraction of two big int depending on the value of
** 		val_exponent:
**   			- val_exponent >= 0:          val_mantissa * 2 ^ (val_exponent)
**              	                  			---------------------------------
**                  	                        		     1
** 				  
*				 - val_exponent < 0:                    val_mantissa
**              			                  ---------------------------------
**                          			             2 ^ (-val_exponent)
** 
**2.Extract the digits as the integer division of numerator by denominator.
** 		
**		Get the power of 10 of the float.point number written in scientific notation
** 		ex. 142.5 = 1.425 * 10^2 --> exponent = 2
**	  
**		Scale th the fraction, so that:               0 <= val_num
**													----------------
**													  val_denom < 10
**		ex.         - 142.5 would become 1.425 --> val_num / (val_den * 10^2)
**  				- 0.01425 would become 1.425 --> val_num / (val_den * 10^-2)
**                                				 --> (val_num * 10^2) / val_den   
**
** 	Repeat until numenator equals 0.
*/

