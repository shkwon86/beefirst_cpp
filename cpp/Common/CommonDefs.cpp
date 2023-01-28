#include "CommonDefs.h"

std::random_device CommonUtils::RandomDevice;
std::mt19937 CommonUtils::RandomGen;

CommonUtils::CommonUtils()
{
	RandomGen.seed(RandomDevice());
}
