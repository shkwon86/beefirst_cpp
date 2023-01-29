#include "Main.h"
#include "../Employee/Database.h"

int main()
{
    ExamLambda lambda;
    lambda.Sort();

    Records::UnitTestDatabase::GetInstance()->Test();
    Records::UnitTestDatabase::GetInstance()->RunInterpreter();

    return 0;
}
