//
//  Vec2.h
//  GameJamEngine
//
//  Created by Goran Esmail on 2015-01-10.
//  Copyright (c) 2015 IP2014. All rights reserved.
//

#pragma once

namespace Math
{

    class Vec2
    {
    public:

        float x;
        float y;
    
        // constructors:
        Vec2();
        Vec2( float x, float y );
    	explicit Vec2( float scalar );
    
        // copy:
        Vec2( const Vec2& vec )             = default;
        Vec2& operator= ( const Vec2& rhs ) = default;
        
        // move:
        Vec2( Vec2&& vec )             = default;
        Vec2& operator= ( Vec2&& vec ) = default;
    
        // operators:
        Vec2  operator- () const;
    
        Vec2  operator+ ( const Vec2& rhs ) const;
        Vec2  operator- ( const Vec2& rhs ) const;
        Vec2  operator* ( float scalar ) const;
        Vec2  operator/ ( float scalar ) const;
    
        Vec2& operator+=( const Vec2& rhs );
    	Vec2& operator-=( const Vec2& rhs );
        Vec2& operator*=( float scalar );
        Vec2& operator/=( float scalar );
    
        // comparison operators:
        bool  operator==( const Vec2& rhs ) const;
        bool  operator!=( const Vec2& rhs ) const;

        // methods:
        float getAngle()      const;
        float getLength()     const;
        Vec2  getNormalized() const;


        float dot( const Vec2& vec )         const;
        Vec2  getRotated ( float angle )     const;
        float getDistance( const Vec2& vec ) const;

    };

    // multiply with scalar:
    Vec2 operator*( float scalar, const Vec2& vec );

    // functions:
    Vec2  normalized( const Vec2& vec );
    float length    ( const Vec2& vec );
    float dot       ( const Vec2& a, const Vec2& b );
    float distance  ( const Vec2& a, const Vec2& b );
    float angle     ( const Vec2& a, const Vec2& b   = Vec2( 1.0f, 0.0f ) );
    Vec2  rotated   ( float angle,   const Vec2& vec = Vec2( 1.0f, 0.0f ) );
    
}
