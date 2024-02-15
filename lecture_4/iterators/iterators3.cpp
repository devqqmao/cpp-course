// Definition of std::move()
// template
// OutputIterator move (InputIterator first, InputIterator last,
//                      OutputIterator result)
// {
//     while (first!=last)
//     {
//         *result = std::move(*first);
//         ++result; ++first; }
//     return result;
// }