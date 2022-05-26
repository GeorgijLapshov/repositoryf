#pragma once

typedef unsigned int ui;

class Money 
{
	friend class Bookkeeper;
	private:
		ui Salary_;
	public:
		Money(ui Salary) 
		{
			Salary_ = Salary;
		}
	const ui& GetSalary() const { return Salary_; };
};