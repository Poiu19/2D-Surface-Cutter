#include <vector>
#include <iostream>
#include "sorting.hpp"
//#include <type_traits>
//std::is_integral<T>::value for checking if it is int

template <>
void sortBubble<int>(std::vector<int> & dataToSort)
{
    std::vector<float> dataToSortConverted(dataToSort.begin(), dataToSort.end());
    sortBubble<float>(dataToSortConverted);
    dataToSort.clear();
    for(toCopy : dataToSortConverted)
        dataToSort.push_back((int)toCopy);
}

template <>
void sortBubble<float>(std::vector<float> & dataToSort)
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

/*
For example - if I want to sort Surface by posX
template <>
void bubbleSort<std::shared_ptr<Surface> >(std::vector<std::shared_ptr<Surface> > & vec)
{
    for(unsigned int i = 0; i < vec.size(); i++)
    {
        for(unsigned int j = 0; j < vec.size()-i-1; j++)
        {
            if(vec[j]->getPosX() > vec[j+1]->getPosX())
                std::swap(vec[j], vec[j+1]);
        }
    }
}*/
