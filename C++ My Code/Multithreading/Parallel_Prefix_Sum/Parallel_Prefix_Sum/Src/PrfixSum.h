#pragma once
#include <future>
#include <numeric>
#include <vector>


std::vector< int > prefix_sum ( std::vector< int >::iterator start , std::vector< int >::iterator end ) {

	std::vector< int > result( end - start );

	if(end - start <= 1000) {
		std::partial_sum( start , end , result.begin() );
		return result;
	}


	std::vector< std::promise< int > > promises( 8 );


	std::vector< std::thread > vec;
	for(int i = 0 ; i < 8 ; i++) {
		auto start_offset = ( ( end - start ) / 8 ) * i;
		auto end_offset   = ( ( end - start ) / 8 ) * ( i + 1 );
		auto began        = start + start_offset;
		auto next         = start + end_offset;
		auto result_start = result.begin() + start_offset;
		vec.push_back( std::thread( [began, next, result_start, &promises ,i] () {
			if(i != 0) {
				*began = *began + promises[i].get_future().get();
			}
			if(i < 7) {
				promises[i + 1].set_value( std::accumulate( began , next , 0 ) );
			}
			std::partial_sum( began , next , result_start );
		} ) );
	}

	for(auto& t : vec) {
		t.join();
	}

	return result;
}
