#pragma once
#include <future>
#include <numeric>


template < typename I , typename T >
T Acc ( I start , I end , T initial ) {
	if(end - start <= 1000) {
		return std::accumulate( start , end , 0 );
	}
	auto middle = ( start + ( ( end - start ) / 2 ) );
	auto f      = std::async( std::launch::async , Acc< I , T > , start , middle , 0 );
	return Acc( middle , end , 0 ) + f.get() + initial;
}
