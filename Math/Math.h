//
//  Math.h
//  GameJamEngine
//
//  Created by Goran Esmail on 2015-01-10.
//  Copyright (c) 2015 IP2014. All rights reserved.
//

#pragma once

namespace Math
{

    namespace cmath
    {
        /*
         * GCC, MSVC and Clang seems to have different
         * ideas about which math functions should
         * used and how they should be named.
         * this is why the C version is included.
         */
        #include <math.h>
    }

    // constants:
    const float EPSILON     = 1E-5f;
    
	const float PI			=  3.14159265358979323846f;
	const float PI_2		=  6.28318530717958647693f;
	const float PI_HALF		=  1.57079632679489661923f;
	const float degToRad	=  0.01745329251994329576f;
	const float radToDeg	= 57.29577951308232087679f;

    // trigonometric functions:
	inline float sin( float f ){ return cmath::sinf( f ); }
	inline float cos( float f ){ return cmath::cosf( f ); }
	inline float tan( float f ){ return cmath::tanf( f ); }
    
    // inverse trigonometric functions:
	inline float asin( float f ){ return cmath::asinf( f ); }
	inline float acos( float f ){ return cmath::acosf( f ); }
	inline float atan( float f ){ return cmath::atanf( f ); }
	
    inline float atan2( float b, float a ){ return cmath::atan2f( b, a ); }

    // logarithmic:
    inline float log  ( float f ){ return cmath::logf  ( f ); }
    inline float log2 ( float f ){ return cmath::log2f ( f ); }
    inline float log10( float f ){ return cmath::log10f( f ); }
	
    // exponential
    inline float sqrt ( float f ){ return cmath::sqrtf( f ); }
    inline float cbrt ( float f ){ return cmath::cbrtf( f ); }
	inline float pow  ( float base, float exponent = 2.0f ) { return cmath::powf( base, exponent ); }
    //inline float pow'2'( float base ){ return base * base; }
	
    // rounding:
    inline float floor( float f ) { return cmath::floorf( f ); }
    inline float ceil ( float f ) { return cmath::ceilf ( f ); }
	inline float round( float f ) { return cmath::roundf( f ); }
	
    // round and convert:
	inline int   floorToInt( float f ){ return static_cast<int>( Math::floor( f ) ); }
	inline int   ceilToInt ( float f ){ return static_cast<int>( Math::ceil ( f ) ); }
	inline int   roundToInt( float f ){ return static_cast<int>( Math::round( f ) ); }

    // max/min:
    inline float max  ( float a, float b ){ return a > b ? a : b; }
    inline float min  ( float a, float b ){ return a < b ? a : b; }
    inline float clamp( float f, float min, float max ){ return Math::max( Math::min( f, max ), min ); }

    // misc:
    inline float abs( float f ){ return cmath::fabs( f ); }
	inline int   abs( int   i ){ return i > 0 ? i : -i ;  }

    inline bool  equals( float a, float b ){ return Math::abs( a - b ) < EPSILON; }
    
	inline float lerp( float a, float b, float alpha ){ return ( a + alpha * ( b - a ) ); }

}
