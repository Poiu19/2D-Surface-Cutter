#include <vector>
#include <iostream>
#include "sorting.hpp"
//#include <type_traits>
//std::is_integral<T>::value for checking if it is int

template <typename T>
void sortBubble(std::vector<T> & dataToSort) //O(n^2)
{
    for(unsigned int i = 0; i < dataToSort.size(); i++)
    {
        for(unsigned int j = 0; j < dataToSort.size()-i-1; j++)
        {
            if(dataToSort[j] > dataToSort[j+1])
                std::swap(dataToSort[j], dataToSort[j+1]);
        }
    }
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

template <typename T>
void
