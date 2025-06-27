#pragma once
#include <future>
#include <algorithm>


template < typename I , typename T >
I PFind ( I start , I end , T match ) {
	if(end - start <= 1000) {
		return std::find( start , end , match );
	}
	int                             block = ( end - start ) / 8;
	std::vector< std::future< I > > futures;
	std::atomic< bool >             found = false;
	for(I it = start ; it < end ; it += block) {
		I next = std::min( it + block , end );
		futures.push_back( std::async( std::launch::async , [it,end, next, &match,&found] {
			for(auto i = it ; i < next ; ++i) {
				if(*i == match) {
					if(!found) {
						found = true;
						return i;
					}
					return end;
				}
			}
			return end;
		} ) );
	}
	for(auto& f : futures) {
		auto value = f.get();
		if(value != end) {
			return value;
		}
	}
	return end - 1;
}
