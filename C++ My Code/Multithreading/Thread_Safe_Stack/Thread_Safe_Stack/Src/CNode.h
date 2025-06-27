#pragma once


template < typename T >
class c_node {

	c_node* next_;
	T       data_;


	public:

		c_node ( T data );

		c_node ( c_node& source );

		c_node ( c_node&& other ) noexcept;

		~c_node ();

		c_node* get_next ();

		void set_next ( c_node* ptr );

		T get_data ();


};


template < typename T >
c_node< T >::c_node ( T data ) : next_( nullptr ), data_( data ) {

}


template < typename T >
c_node< T >::c_node ( c_node& source ) {
	this->next_ = new c_node( source.data_ );

}


template < typename T >
c_node< T >::c_node ( c_node&& source ) noexcept : data_( source.data_ ), next_( source.next_ ) {
	source.next_ = nullptr;
}


template < typename T >
c_node< T >::~c_node () {
	while(this->next_ != nullptr) {
		c_node< T >* node = this->next_;
		this->next_       = this->next_->get_next();
		node->set_next( nullptr );
		delete node;
	}
	delete this->next_;
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
