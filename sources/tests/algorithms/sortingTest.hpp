#include <vector>
#include <time.h>
#include <stdlib.h>
#include "algorithms/sorting.hpp"
#include "headers.hpp"
template <typename T>
struct SortingDataTest{
	std::vector<T> testDataInput;
	std::vector<T> testDataOutput;
	SortingDataTest(SortType sortBy, int testSize = 100)
	{
		srand(time(NULL));
		T value = (T)0.0;
		while (testDataOutput.size() != testSize)
		{
			if ((rand() % 100 + 1) <= 10)
				testDataOutput.push_back(value);
			value++;
		}
		std::vector<T> testDataOutputCopy(testDataOutput.begin(), testDataOutput.end());
		while (testDataInput.size() != testSize)
		{
			int i = rand() % testDataOutputCopy.size();
			testDataInput.push_back(testDataOutputCopy[i]);
			testDataOutputCopy.erase(testDataOutputCopy.begin() + i);

		}
		if (sortBy == SORT_BUBBLE)
			SortingAlgorithms::sortBubble<T>(testDataInput);
		else if (sortBy == SORT_QUICK)
			SortingAlgorithms::sortQuick<T>(testDataInput);

	}
	public: bool isEqual()
	{
		return testDataInput == testDataOutput ? true : false;
	}
};