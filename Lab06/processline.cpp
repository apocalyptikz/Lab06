//============================================================================
// Name        : processline.cpp
// Author      : Jonathan Christian
// Version     : 0.0.1
// Copyright   : 
// Description : processline for postfix calculator
//============================================================================

#include <cctype>     // Provides isdigit
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <cstring>    // Provides strchr
#include <iostream>   // Provides cout, cin, peek, ignore
#include "mystack.h"


	/*
Reads the next line of input (including the newline character at the end of the line). It treats this input line as an arithmetic expression.
If the expression has an error (such as division by zero), then the function returns nan("Invalid").
Otherwise, the function sets okay to true and sets answer to the value of the expression.

Here are a few considerations:
   The input expressions are postfix expressions.
   Use the evaluation algorithm from Figure 7.10 in the textbook.

   The possible errors that will cause a return of nan("Invalid"):
	   (a) division by zero,
	   (b) an operation symbol is read but the stack does not have at least two numbers,
	   (c) the entire expression has been read and evaluated but the numbers stack does not have exactly one number on it.
*/
	double process_line(std::istream& ins)
	{
		double number;
		const char DECIMAL = '.';
		DS::mystack<double> mathStack;
		while (ins && ins.peek() != '\n')
		{
			if (isdigit(ins.peek()) || ins.peek() == DECIMAL)
			{
				ins >> number;
				mathStack.push(number);
			}
			else if (strchr("-*+/", ins.peek()) != NULL)
			{
				char operation;
				ins >> operation;
				//get numbers top
				double num2 = mathStack.top();
				mathStack.pop();
				double num1 = mathStack.top();
				mathStack.pop();
				
				switch (operation)
				{
				case '-':
					mathStack.push(num1 - num2);
					break;
				case '+':
					mathStack.push(num1 + num2);
					break;
				case '/':
					if (num2 == 0)
					{
						ins.ignore();
						return std::nan("Invalid");
					}
						
					mathStack.push(num1 / num2);
					break;
				case '*':
					mathStack.push(num1 * num2);
					break;
				}
			}
			else
				ins.ignore();
		}
		ins.ignore();
		return mathStack.top();
	}



