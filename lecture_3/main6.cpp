#include <cmath>
#include <vector>
#include <unordered_map>
#include <iostream>

// public interface; dynamic array
struct IntArray
{
    void resize(size_t nsize)
    {
        int *ndata = new int[nsize];
        size_t n = nsize > size_ ? size_ : nsize;

        for (size_t i = 0; i != n; ++i)
        {
            ndata[i] = data_[i];
        }

        delete[] data_;
        data_ = ndata;
        size_ = nsize;
    }

private:
    size_t size_;
    int *data_;
};

// Abstraction
struct IntArray
{
public:
    explicit IntArray(size_t size) : size_(size), data_(new int[size]) {}

    ~IntArray() { delete[] data_; }

    int &get(size_t i) { return data_[i]; }
    size_t size() { return size_; }

    // An ampersand just before the function name will return a
    // reference to the variable instead of returning its value

private:
    size_t size_;
    int *data_;
};

// Abstraction store size in the first element;
struct IntArray
{
public:
    explicit IntArray(size_t size) : data_(new int[size + 1])
    {
        data_[0] = size;
    }
    ~IntArray() { delete[] data_; }

    int &get(size_t i) { return data_[i + 1]; }
    size_t size() { return data_[0]; }

private:
    int *data_;
};

int main()
{
    return 0;
}