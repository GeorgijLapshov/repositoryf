#pragma once
#include <iostream>

using std::string;

class Initials 
{
	private:
		string FullName_;
	public:
		Initials (const string& FullName="Nullbody")
		{
			FullName_ = FullName;
		}
		const string& GetName() const { return FullName_; };
};