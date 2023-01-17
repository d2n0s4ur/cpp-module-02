/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:45:00 by jnoh              #+#    #+#             */
/*   Updated: 2023/01/15 18:29:25 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					value_;
		static const int	fractional_bits_ = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int value);
		Fixed(const float value);
		Fixed	&operator= (const Fixed &fixed);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<< (std::ostream& outputStream, const Fixed &fixed);

#endif
