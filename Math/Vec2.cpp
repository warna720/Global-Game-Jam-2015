//
//  Vec2.cpp
//  GameJamEngine
//
//  Created by Goran Esmail on 2015-01-10.
//  Copyright (c) 2015 IP2014. All rights reserved.
//

#include "Vec2.h"
#include "Math.h"

using namespace Math;

// constructors:
Vec2::Vec2()
  : x( 0.0f ), y( 0.0f )
{}

Vec2::Vec2( float x, float y )
  : x( x ), y( y )
{}

Vec2::Vec2( float scalar )
  : x( scalar ), y( scalar )
{}

// operators:
Vec2 Vec2::operator-() const
{
    return Vec2( -x, -y );
}

Vec2 Vec2::operator+( const Vec2& rhs ) const
{
    return Vec2( x + rhs.x, y + rhs.y );
}

Vec2 Vec2::operator-( const Vec2& rhs ) const
{
    return Vec2( x - rhs.x, y - rhs.y );
    // return ( *this + -rhs ); // less redundant?
}

Vec2 Vec2::operator* ( float scalar ) const
{
    return Vec2( x * scalar, y * scalar );
}

Vec2 Vec2::operator/ ( float scalar ) const
{
    return Vec2( x / scalar, y / scalar );
}

Vec2& Vec2::operator+=( const Vec2& rhs )
{
    return ( *this = *this + rhs );
}

Vec2& Vec2::operator-=( const Vec2& rhs )
{
    return ( *this = *this - rhs );
    // *this += -rhs; // less redundant?
}

Vec2& Vec2::operator*=( float scalar )
{
    return ( *this = *this * scalar );
}

Vec2& Vec2::operator/=( float scalar )
{
    return ( *this = *this / scalar );
}

// comparison operators:
bool Vec2::operator==( const Vec2& rhs ) const
{
    return ( equals( x, rhs.x ) and equals( y, rhs.y ) );
}

bool Vec2::operator!=( const Vec2& rhs ) const
{
    return not ( *this == rhs );
}

// methods:
float Vec2::getAngle() const
{
    return atan2( y, x );
}

float Vec2::getLength() const
{
    return sqrt( pow( x ) + pow( y ) );
}

Vec2 Vec2::getNormalized() const
{
    return ( *this / getLength() );
}

float Vec2::dot( const Vec2& vec ) const
{
    return ( x * vec.x + y * vec.y );
}

Vec2 Vec2::getRotated( float angle ) const
{
    const Vec2 rotated_unit_vector( cos( angle ), sin( angle ) );
    
    return rotated_unit_vector.x * Vec2( x, y ) - rotated_unit_vector.y * Vec2( y, -x );
}

float Vec2::getDistance( const Vec2& vec ) const
{
    return ( vec - *this ).getLength();
}

// multiply with scalar:
Vec2 operator*( float scalar, const Vec2& vec )
{
    return vec * scalar;
}

// functions:
Vec2 normalized( const Vec2& vec )
{
    return vec.getNormalized();
}

float length( const Vec2& vec )
{
    return vec.getLength();
}

float dot( const Vec2& a, const Vec2& b )
{
    return a.dot( b );
}

float distance( const Vec2& a, const Vec2& b )
{
    return a.getDistance( b );
}

float angle( const Vec2& vec )
{
    return vec.getAngle();
}

float angle( const Vec2& a, const Vec2& b )
{
    return b.getAngle() - a.getAngle(); // use abs here?
}

Vec2 rotated( float angle, const Vec2& vec )
{
    return vec.getRotated( angle );
}
