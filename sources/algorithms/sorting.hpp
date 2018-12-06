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
};
#endif // SORTING_HPP_INCLUDED
