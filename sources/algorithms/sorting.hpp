#ifndef SORTING_HPP_INCLUDED
#define SORTING_HPP_INCLUDED
#include <vector>
#include <iostream>
namespace SortingAlgorithms
{
    template <typename T>
    void sortBubble(std::vector<T> & dataToSort)
    {
        int positionMin = 0, positionMax = dataToSort.size()-2, position;
        do
        {
            position = -1;
            for(int i = positionMin; i <= positionMax; i++)
            {
                if(dataToSort[i] > dataToSort[i+1])
                {
                    std::swap(dataToSort[i], dataToSort[i+1]);
                    position = i;
                }
            }
            if(position < 0)
                break;
            positionMax = position - 1;
            position = -1;
            for(int i = positionMax; i >= positionMin; i--)
            {
                if(dataToSort[i] > dataToSort[i+1])
                {
                    std::swap(dataToSort[i], dataToSort[i+1]);
                    position = i;
                }
            }
            positionMin = position + 1;
        } while (position >= 0);
    }

    template <typename T>
    struct SortQuick
    {
        public: static void execute(std::vector<T> & dataToSort, int startPoint, int edgePoint)
        {
            int splitPoint;
            if(startPoint < edgePoint)
            {
                splitPoint = divisionData(dataToSort, startPoint, edgePoint);
                execute(dataToSort, startPoint, splitPoint); //first part of table
                execute(dataToSort, splitPoint+1, edgePoint);
            }
        }

        static int divisionData(std::vector<T> & dataToSort, int startPoint, int edgePoint)
        {
            int splitPointValue = dataToSort[startPoint];
            int i = startPoint, j = edgePoint; //table indexes
            while(true)
            {
                while(dataToSort[j] > splitPointValue)
                    j--;
                while(dataToSort[i] < splitPointValue)
                    i++;
                if(i < j) //checking if split is necessary
                {
                    std::swap(dataToSort[i], dataToSort[j]);
                    i++;
                    j--;
                }
                else //returning new splitPoint
                    return j;
            }
        }
    };

    template <typename T>
    void sortQuick(std::vector<T> & dataToSort)
    {
        SortQuick<T>::execute(dataToSort, 0, dataToSort.size()-1);
	}

	template <typename T>
	struct SortHeap {
		static void buildHeap(std::vector<T> & dataToSort, int heapSize, int i)
		{
			int root = i;
			int leftChild = 2 * i + 1;
			int rightChild = 2 * i + 2;
			//Why 2*i + 1 and 2*i + 2; ?
			//Input data: 5, 9, 10, 44, 23, 55, 23, 1
			//                        5 (i = 0)
			//						/			\
			//					  9 (1)       10 (2)
			//					/		\	   /	\
			//				44 (3)  23  (4)  55 (5)  23 (6)
			//				/
			//			 1 (7)
			// Child for i=0 - 2*0+1 and 2*0+2 = 1 and 2; It's true
			// Child for i=1 - 2*1+1 and 2*1+2 = 3 and 4; It's true
			// Child for i=2 - 2*2+1 and 2*2+2 = 5 and 6; It's true
			// Child for i=3 - 2*3+1 and null = 7 and null; It's true
			if (leftChild < heapSize && dataToSort[leftChild] > dataToSort[root])
				root = leftChild;

			if (rightChild < heapSize && dataToSort[rightChild] > dataToSort[root])
				root = rightChild;

			if (root != i)
			{
				std::swap(dataToSort[i], dataToSort[root]);
				buildHeap(dataToSort, heapSize, root);
			}
		}
		public: static void execute(std::vector<T> & dataToSort, int dataSize)
		{
			for (int i = dataSize / 2 - 1; i >= 0; i--)
				buildHeap(dataToSort, dataSize, i);
			for (int i = dataSize - 1; i >= 0; i--)
			{
				std::swap(dataToSort[0], dataToSort[i]);
				buildHeap(dataToSort, i, 0);
			}
		}
	};

	template <typename T>
	void sortHeap(std::vector<T> & dataToSort)
	{
		SortHeap<T>::execute(dataToSort, dataToSort.size());
	}
};
#endif // SORTING_HPP_INCLUDED
