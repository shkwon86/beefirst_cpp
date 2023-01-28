#include "Lambda.h"
#include "../Common/CommonDefs.h"

// sort
void ExamLambda::Sort()
{
	const size_t _COUNT = 10;
	std::vector<int> _numbers;

	// 1~100 ���� ������ ���� _COUNT ����
	CommonUtils::GetInstance()->GetRandoms<int>(1, 100, _COUNT, _numbers);

	std::cout << "Random numbers: ";
	for (auto& i : _numbers)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	// ������������ ���� (use lambda)
	std::sort(_numbers.begin(), _numbers.end(), [](int lhs, int rhs) { return lhs < rhs; });

	std::cout << "Sorted numbers: ";
	for (auto& i : _numbers)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
