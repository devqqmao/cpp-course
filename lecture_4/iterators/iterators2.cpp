// Input Iterators in C++


// <strong>// Definition of std::copy()</strong>
// template
// OutputIterator copy(InputIterator first, InputIterator last,
//                     OutputIterator result)
// {
// while (first != last) *result++ = *first++;
// return result;
// }

// <strong>// Definition of std::find()</strong>
// template
// InputIterator find (InputIterator first, InputIterator last,
// const T& val)
// {
// while (first!=last) {
// if (*first==val) return first;
// ++first;
// }
// return last; }
