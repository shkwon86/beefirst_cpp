#pragma once

/*
* 요구사항
* 1. 채용
* 2. 해고
* 3. 승진
* 4. 과거, 현재 직원 모두 조회
* 5. 현재 직원 모두 조회
* 6. 과거 직원 모두 조회
*/

#include "../Common/CommonDefs.h"

namespace Records
{
	const int kDefaultStartingSalary = 30000;

	class Employee
	{
	public:

		Employee() = default;
		Employee(const std::string& _firstName, const std::string& _lastName);

		void Promote(int raiseAmount = 1000);
		void Demote(int demeritAmount = 1000);
		void Hire();
		void Fire();
		void Display() const;

		// getter & setter
		void SetFirstName(const std::string& _firstName) { firstName = _firstName; }
		const std::string& GetFirstName() const { return firstName; }
		void SetLastName(const std::string& _lastName) { lastName = _lastName; }
		const std::string& GetLastName() const { return lastName; }

		void SetEmployeeNumber(int _number) { employeeNumber = _number; }
		int GetEmployeeNumber() const { return employeeNumber; }

		void SetSalay(int _salay) { salay = _salay; }
		int GetSalay() const { return salay; }

		bool IsHire() const { return hired; }

	private:
		std::string firstName;
		std::string lastName;
		int employeeNumber = -1;
		int salay = Records::kDefaultStartingSalary;
		bool hired = false;
	};
}
