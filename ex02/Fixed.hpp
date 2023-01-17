/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:45:00 by jnoh              #+#    #+#             */
/*   Updated: 2023/01/17 16:25:21 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					value_;
		static const int	fractional_bits_ = 8;
	public:
		Fixed();
		~Fixed();
		Fixed( const Fixed &fixed );
		Fixed( const int value );
		Fixed( const float value );
		Fixed	&operator= ( const Fixed &fixed );

		bool	operator> ( Fixed const &fixed ) const;
		bool	operator< ( Fixed const &fixed ) const;
		bool	operator>= ( Fixed const &fixed ) const;
		bool	operator<= ( Fixed const &fixed ) const;
		bool	operator== ( Fixed const &fixed ) const;
		bool	operator!= ( Fixed const &fixed ) const;

		Fixed	operator+ ( Fixed const &fixed ) const;
		Fixed	operator- ( Fixed const &fixed ) const;
		Fixed	operator* ( Fixed const &fixed ) const;
		Fixed	operator/ ( Fixed const &fixed ) const;

		Fixed		&operator++ ( void );
		Fixed		&operator-- ( void );
		const Fixed	operator++ ( int );
		const Fixed	operator-- ( int );

		static Fixed		&max( Fixed &a, Fixed &b );
		static Fixed		&min( Fixed &a, Fixed &b );
		static Fixed const	&max( Fixed const &a, Fixed const &b );
		static Fixed const	&min( Fixed const &a, Fixed const &b );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<< (std::ostream& outputStream, const Fixed &fixed);

#endif
