#pragma once

#include "Employee.h"
#include "../Common/Singleton.h"

namespace Records
{
	const int kFirstEmployeeNumber = 1000;
	class Database
	{
	public :
		Employee& AddEmployee(const std::string& _firstName, const std::string& _lastName);
		Employee& GetEmployee(int employeeNumber);
		Employee& GetEmployee(const std::string& _firstName, const std::string& _lastName);

		void DisplayAll() const;
		void DisplayCurrent() const;
		void DisplayFormer() const;

	private :
		std::vector<Employee> employees;
		int nextEmployeeNumber = kFirstEmployeeNumber;
	};


	class UnitTestDatabase : public Singleton<UnitTestDatabase>
	{
		friend Singleton;
		UnitTestDatabase();

	public :
		void Test();

	public :
		void RunInterpreter();

		int DisplayMenu();
		void DoHire(Database& db);
		void DoFire(Database& db);
		void DoPromote(Database& db);
		void DoDemote(Database& db);
	};
}

