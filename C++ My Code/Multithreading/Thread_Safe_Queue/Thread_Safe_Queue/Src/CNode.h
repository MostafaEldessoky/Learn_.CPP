#pragma once


template < typename T >
class c_node {
	T       data_;
	c_node* next_;


	public:

		c_node ( T );

		~c_node ();

		c_node ( const c_node& source );

		c_node ( c_node&& source );

		c_node* get_next ();

		void set_next ( c_node* );

		T get_data ();

};


template < typename T >
c_node< T >::c_node ( T data ) : data_( data ), next_( nullptr ) {

}


template < typename T >
c_node< T >::~c_node () {
	while(this->next_ != nullptr) {
		auto ptr    = this->next_;
		this->next_ = this->next_->get_next();
		ptr->set_next( nullptr );
		delete ptr;
	}
}


template < typename T >
c_node< T >::c_node ( const c_node& source ) : next_( new c_node( source.data_ ) ) {
}


template < typename T >
c_node< T >::c_node ( c_node&& source ) : data_( source.data_ ), next_( source.next_ ) {
	source.next_ = nullptr;
}


template < typename T >
c_node< T >* c_node< T >::get_next () {
	return this->next_;
}


template < typename T >
void c_node< T >::set_next ( c_node* ptr ) {
	this->next_ = ptr;
}


template < typename T >
T c_node< T >::get_data () {
	return this->data_;
}
