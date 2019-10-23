/*
Program Name: Lab x
Programmer Name: Prof. Miller
Date Submitted: Not submitted
File Purpose: single linked node
Date Updated: n/a
Purpose for Update: n/a
Global Variable List: n/a (avoid these)
*/

#ifndef NODE_LL_H_
#define NODE_LL_H_

namespace DSLL {

template <typename T>
class node
{
public:
	typedef T value_type;
	node(value_type d = value_type(), node * n = nullptr) { data = d; next = n; }

	//Assessor/Getters
	value_type getData () const { return data; }
	node const * getNext () const { return next; }

	//Mutators/Setters
	void setData (const value_type& d) {data = d; }
	void setNext (node * new_link) {next = new_link; }
	node*& getNext () { return next; }

private:
	value_type data;
	node* next;
};


} /* namespace DSLL */

#endif /* NODE_LL_H_ */
