#ifndef SORTING_HPP_INCLUDED
#define SORTING_HPP_INCLUDED

template <typename T>
void sortBubble(std::vector<T> & dataToSort);

template <>
void sortBubble(std::vector<int> & dataToSort);
template <>
void sortBubble(std::vector<float> & dataToSort);
#endif // SORTING_HPP_INCLUDED
