#ifndef SORTING_HPP_INCLUDED
#define SORTING_HPP_INCLUDED
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
};
#endif // SORTING_HPP_INCLUDED
