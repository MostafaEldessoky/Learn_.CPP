#pragma once
#include <future>
#include <algorithm>


template < typename I , typename F >
void forEach ( I start , I end , F f ) {
	if(end - start <= 1000) {
		std::for_each( start , end , f );
	}
	else {
		int                                block = ( end - start ) / 8;
		std::vector< std::future< void > > futures;
		for(I it = start ; it < end ; it += block) {
			I next = std::min( it + block , end );
			futures.push_back( std::async( std::launch::async , [it,next,f] {
				std::for_each( it , next , f );
			} ) );
		}
	}
}
