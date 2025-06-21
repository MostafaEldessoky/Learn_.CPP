#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

std::mutex mtx;

class Myclass {
public:

	Myclass( ) = default;

	void operator( )( int& x , int y ) {
		std::this_thread::sleep_for( std::chrono::milliseconds( x ) );
		mtx.lock( );
		std::cout << std::this_thread::get_id( ) << " is doing work from functor" << std::endl;
		mtx.unlock( );
		std::this_thread::sleep_for( std::chrono::milliseconds( y ) );
		}
	void fn( int x , int y , std::string&& s ) {
		std::cout << "Thread name: " << s << std::endl;
		std::this_thread::sleep_for( std::chrono::milliseconds( x ) );
		mtx.lock( );
		std::cout << std::this_thread::get_id( ) << " is doing work from functor fn" << std::endl;
		mtx.unlock( );
		std::this_thread::sleep_for( std::chrono::milliseconds( y ) );
		}
	};

void fn( int x , int& y ) {
	std::this_thread::sleep_for( std::chrono::milliseconds( x ) );
	mtx.lock( );
	std::cout << std::this_thread::get_id( ) << " is doing work from fn" << std::endl;
	mtx.unlock( );
	std::this_thread::sleep_for( std::chrono::milliseconds( y ) );
	}

int main( ) {

	int x = 100;
	int y = 200;
	int z = 300;
	std::string s = "Hello string s";

	auto func = [&z]( int x , int y ) {
		z = 400;
		std::this_thread::sleep_for( std::chrono::milliseconds( x ) );
		mtx.lock( );
		std::cout << std::this_thread::get_id( ) << " is doing work from func" << std::endl;
		mtx.unlock( );
		std::this_thread::sleep_for( std::chrono::milliseconds( y ) );
		};

	Myclass myclass;

	std::vector<std::thread> vec;

	vec.push_back( std::thread( func , x , y ) );
	vec.push_back( std::thread( myclass , std::ref( x ) , y ) );
	vec.push_back( std::thread( fn , x , std::ref( y ) ) );
	vec.push_back( std::thread( &Myclass::fn , &myclass , x , y , std::move( s ) ) );

	for( auto& t : vec ) {
		if( t.joinable( ) ) {
			t.join( );
			}
		}

	std::cout << "Final value of z: " << z << std::endl;
	std::cout << s.empty( ) << " " << std::endl;

	return 0;
	}