/*
 * mystack.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: steve
 */


#include <cassert>
#include "mystack.h"

namespace DS {

mystack::mystack(const mystack& source)
{
	if ( source.pTop == nullptr ) {
		//Source list is empty, initialize member data
		pTop = nullptr;
	} else {
		node_type *tail;
		//Special case, add a new head node
		pTop = tail = new node_type(source.pTop->getData());
		//Loop until no more nodes to add
		for ( node_type * p = source.pTop->getNext() ; p != nullptr ; p = p->getNext()  ) {
			tail->setNext(new node_type(source.pTop->getData()));
			tail = tail->getNext();
		}
	}
	node_count = source.node_count;
}

mystack::~mystack()
{
	node_type *temp;
	while ( pTop != nullptr ) {
		temp = pTop;
		pTop = pTop->getNext();
		delete temp;
	}
}

void mystack::push(const value_type& entry)
{
    pTop = new node_type(entry,pTop);
    ++node_count;
}

void mystack::pop( )
// Library facilities used: cassert
{
    assert(!empty( ));
    DSLL::node<value_type> *temp;
    temp = pTop;
	pTop = pTop->getNext();
	delete temp;
    --node_count;
}

void mystack::operator =(const mystack& source)
{
    if (this == &source) // Handle self-assignment
        return;

    //Delete old
    node_type *temp;
	while ( pTop != nullptr ) {
		temp = pTop;
		pTop = pTop->getNext();
		delete temp;
	}

	if ( source.pTop == nullptr ) {
		//Source list is empty, initialize member data
		pTop = nullptr;
	} else {
		node_type *tail;
		//Special case, add a new head node
		pTop = tail = new node_type(source.pTop->getData());
		//Loop until no more nodes to add
		for ( node_type * p = source.pTop->getNext() ; p != nullptr ; p = p->getNext()  ) {
			tail->setNext(new node_type(source.pTop->getData()));
			tail = tail->getNext();
		}
	}
	node_count = source.node_count;

}

typename mystack::value_type mystack::top( ) const
{
    assert(!empty( ));
    return pTop->getData();
}

} /* namespace ss */
