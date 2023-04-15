#include "Database.h"
#include <stdexcept>

namespace Records
{
	Employee& Database::AddEmployee(const std::string& _firstName, const std::string& _lastName)
	{
		Employee new_employee;
		new_employee.SetFirstName(_firstName);
		new_employee.SetLastName(_lastName);
		new_employee.SetEmployeeNumber(nextEmployeeNumber++);
		new_employee.Hire();

		employees.push_back(new_employee);

		return employees[employees.size() - 1];
	}
	Employee& Database::GetEmployee(int employeeNumber)
	{
		auto findIt = std::find_if(employees.begin(), employees.end(), 
			[employeeNumber](auto& emp) {
				return (emp.GetEmployeeNumber() == employeeNumber);
			});

		if (findIt != employees.end())
			return *findIt;

		throw std::logic_error("No employee found.");
	}
	Employee& Database::GetEmployee(const std::string& _firstName, const std::string& _lastName)
	{
		auto findIt = std::find_if(employees.begin(), employees.end(),
			[&_firstName, &_lastName](auto& emp) {
				return (emp.GetFirstName() == _firstName && emp.GetLastName() == _lastName);
			});

		if (findIt != employees.end())
			return *findIt;

		throw std::logic_error("No employee found.");
	}
	void Database::DisplayAll() const
	{
		for (const auto& it : employees)
		{
			it.Display();
		}
	}
	void Database::DisplayCurrent() const
	{
		for (const auto& it : employees)
		{
			if (it.IsHire())
				it.Display();
		}
	}
	void Database::DisplayFormer() const
	{
		for (const auto& it : employees)
		{
			if (it.IsHire() == false)
				it.Display();
		}
	}

	/// <summary>
	/// unit test
	/// </summary>
	UnitTestDatabase::UnitTestDatabase()
	{
	}
	void UnitTestDatabase::Test()
	{
		Database testDB;

		Employee& emp1 = testDB.AddEmployee("Ava", "Parker");
		emp1.Fire();

		Employee& emp2 = testDB.AddEmployee("Ethan", "Smith");
		emp2.SetSalay(110000);

		Employee& emp3 = testDB.AddEmployee("Mia", "Johnson");
		emp3.SetSalay(100000);
		emp3.Promote();

		std::cout << "---[all employees]---" << std::endl;
		testDB.DisplayAll();

		std::cout << "---[current employees]---" << std::endl;
		testDB.DisplayCurrent();

		std::cout << "---[former employees]---" << std::endl;
		testDB.DisplayFormer();
	}

	void UnitTestDatabase::RunInterpreter()
	{
		Database employeeDB;
		bool done = false;

		while (!done)
		{
			int selection = DisplayMenu();
			switch (selection)
			{
			case 0: done = true;					break;
			case 1: DoHire(employeeDB);				break;
			case 2: DoFire(employeeDB);				break;
			case 3: DoPromote(employeeDB);			break;
			case 4: DoDemote(employeeDB);			break;
			case 5: employeeDB.DisplayAll();		break;
			case 6: employeeDB.DisplayCurrent();	break;
			case 7: employeeDB.DisplayFormer();		break;
			default:
				std::cout << "unknown command." << std::endl;
				break;
			}
		}
	}
	int UnitTestDatabase::DisplayMenu()
	{
		int selection = 0;

		std::cout << std::endl;
		std::cout << "Employee Database" << std::endl;
		std::cout << "----------------------" << std::endl;
		std::cout << "1. Hire a new employee" << std::endl;
		std::cout << "2. Fire an employee" << std::endl;
		std::cout << "3. Promote an employee" << std::endl;
		std::cout << "4. Demote an employee" << std::endl;
		std::cout << "5. List all employees" << std::endl;
		std::cout << "6. List all current employees" << std::endl;
		std::cout << "7. List all former employees" << std::endl;
		std::cout << "0. Quit" << std::endl;
		std::cout << std::endl;
		std::cout << "---> ";
		std::cin >> selection;

		return selection;
	}
	void UnitTestDatabase::DoHire(Database& db)
	{
		std::string firstName;
		std::string lastName;

		std::cout << "First name? ";
		std::cin >> firstName;

		std::cout << "Last name? ";
		std::cin >> lastName;

		db.AddEmployee(firstName, lastName);
	}
	void UnitTestDatabase::DoFire(Database& db)
	{
		int employeeNumber = 0;

		std::cout << "Fire employee number? ";
		std::cin >> employeeNumber;

		try
		{
			Employee& emp = db.GetEmployee(employeeNumber);
			emp.Fire();

			std::cout << "Employee: " << employeeNumber << " terminated." << std::endl;
		}
		catch (const std::logic_error& exception)
		{
			std::cerr << "Unable to terminate employee: " << exception.what() << std::endl;
		}
	}
	void UnitTestDatabase::DoPromote(Database& db)
	{
		int emplyeeNumber = 0;
		int raiseAmount = 0;

		std::cout << "Employee number? ";
		std::cin >> emplyeeNumber;

		std::cout << "How much of a raise? ";
		std::cin >> raiseAmount;

		try
		{
			Employee& emp = db.GetEmployee(emplyeeNumber);
			emp.Promote(raiseAmount);
		}
		catch (const std::logic_error& exception)
		{
			std::cerr << "Unable to promote employee: " << exception.what() << std::endl;
		}
	}
	void UnitTestDatabase::DoDemote(Database& db)
	{
		int emplyeeNumber = 0;
		int demeritAmount = 0;

		std::cout << "Employee number? ";
		std::cin >> emplyeeNumber;

		std::cout << "How much of a demerit? ";
		std::cin >> demeritAmount;

		try
		{
			Employee& emp = db.GetEmployee(emplyeeNumber);
			emp.Demote(demeritAmount);
		}
		catch (const std::logic_error& exception)
		{
			std::cerr << "Unable to demote employee: " << exception.what() << std::endl;
		}
	}
}
