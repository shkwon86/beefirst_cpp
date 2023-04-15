#include "Employee.h"

namespace Records
{
	
	Employee::Employee(const std::string& _firstName, const std::string& _lastName)
		: firstName(_firstName)
		, lastName(_lastName)
	{
	}

	void Employee::Promote(int raiseAmount)
	{
		SetSalay(GetSalay() + raiseAmount);
	}

	void Employee::Demote(int demeritAmount)
	{
		SetSalay(GetSalay() - demeritAmount);
	}

	void Employee::Hire()
	{
		hired = true;
	}

	void Employee::Fire()
	{
		hired = false;
	}

	void Employee::Display() const
	{
		std::cout << "Employee: " << GetFirstName() << ", " << GetLastName() << std::endl;
		std::cout << "---------------------------" << std::endl;
		std::cout << (IsHire() ? "Current Employee" : "Former Employee") << std::endl;
		std::cout << "Employee Number: " << GetEmployeeNumber() << std::endl;
		std::cout << "Salay: $" << GetSalay() << std::endl;
		std::cout << std::endl;
	}

}
