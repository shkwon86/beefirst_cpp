#include "Lambda.h"
#include "../Common/CommonDefs.h"

// sort
void ExamLambda::Sort()
{
	const size_t _COUNT = 10;
	std::vector<int> _numbers;

	// 1~100 까지 랜덤한 수를 _COUNT 생성
	CommonUtils::GetInstance()->GetRandoms<int>(1, 100, _COUNT, _numbers);

	std::cout << "Random numbers: ";
	for (auto& i : _numbers)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	// 오름차순으로 정렬 (use lambda)
	std::sort(_numbers.begin(), _numbers.end(), [](int lhs, int rhs) { return lhs < rhs; });

	std::cout << "Sorted numbers: ";
	for (auto& i : _numbers)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
