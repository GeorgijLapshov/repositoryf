#pragma once
#include <string>
#include <vector>
#include "Initials.h"
#include "Money.h"

using std::string;
using std::vector;

class Employee :
	public Initials, public Money
{
	protected:
		string Post_;
	public:
		friend class Bookkeeper;
		Employee(const string& FullName, ui Salary);
	
		const string& GetPost() const { return Post_;};
		virtual void ShowThis() = 0;
		~Employee();
};

