/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:47:38 by jnoh              #+#    #+#             */
/*   Updated: 2023/01/17 16:26:48 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static float	ft_pow(float base, int n)
{
	float	ret;

	ret = 1;
	while (n > 0)
	{
		ret *= base;
		n--;
	}
	while (n < 0)
	{
		ret /= base;
		n++;
	}
	return (ret);
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value_ = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	this->value_ = (int)(value * ft_pow(2, this->fractional_bits_));
}

Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called" << std::endl;
	this->value_ = (int)std::roundf(value * ft_pow(2, this->fractional_bits_));
}

Fixed	&Fixed::operator= ( const Fixed &fixed )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value_ = fixed.getRawBits();
	return (*this);
}

bool	Fixed::operator> ( Fixed const &fixed ) const
{
	return (this->value_ > fixed.value_);
}

bool	Fixed::operator< ( Fixed const &fixed ) const
{
	return (this->value_ < fixed.value_);
}

bool	Fixed::operator>= ( Fixed const &fixed ) const
{
	return (this->value_ >= fixed.value_);
}

bool	Fixed::operator<= ( Fixed const &fixed ) const
{
	return (this->value_ <= fixed.value_);
}

bool	Fixed::operator== ( Fixed const &fixed ) const
{
	return (this->value_ == fixed.value_);
}

bool	Fixed::operator!= ( Fixed const &fixed ) const
{
	return (this->value_ != fixed.value_);
}

Fixed	Fixed::operator+ ( Fixed const &fixed ) const
{
	Fixed ret(this->toFloat() + fixed.toFloat());

	return (ret);
}

Fixed	Fixed::operator- ( Fixed const &fixed ) const
{
	Fixed ret(this->toFloat() - fixed.toFloat());

	return (ret);
}

Fixed	Fixed::operator* ( Fixed const &fixed ) const
{
	Fixed ret(this->toFloat() * fixed.toFloat());

	return (ret);
}

Fixed	Fixed::operator/ ( Fixed const &fixed ) const
{
	Fixed ret(this->toFloat() / fixed.toFloat());

	return (ret);
}

Fixed	&Fixed::operator++ ( void )
{
	++(this->value_);
	return (*this);
}

Fixed	&Fixed::operator-- ( void )
{
	--(this->value_);
	return (*this);
}

const Fixed	Fixed::operator++ ( int )
{
	const Fixed tmp(this->toFloat());

	++(*this);
	return (tmp);
}

const Fixed	Fixed::operator-- ( int )
{
	const Fixed tmp(this->toFloat());

	--(*this);
	return (tmp);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b )
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::min( Fixed &a, Fixed &b )
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

Fixed const	&Fixed::max( Fixed const &a, Fixed const &b )
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

Fixed const	&Fixed::min( Fixed const &a, Fixed const &b )
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

int	Fixed::getRawBits( void ) const
{
	return (this->value_);
}

void	Fixed::setRawBits( int const raw )
{
	this->value_ = raw;
}

float	Fixed::toFloat( void ) const
{
	return (this->value_ * ft_pow(2, (-1) * this->fractional_bits_));
}

int	Fixed::toInt( void ) const
{
	return ((int)(this->value_ * ft_pow(2, (-1) * this->fractional_bits_)));
}

std::ostream	&operator<< (std::ostream& outputStream, const Fixed &fixed)
{
	outputStream << fixed.toFloat();
	return (outputStream);
}
