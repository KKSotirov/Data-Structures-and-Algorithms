#include <iostream>
#include <utility>

template <typename T>
class Vector
{
private:
    T *data;
    size_t size;
    size_t cap;

    void resize()
    {
        T *tmp = new T[cap * 2];
        try
        {

            for (size_t i = 0; i < size; i++)
                tmp[i] = data[i];
        }
        catch (...)
        {
            delete[] tmp;
            throw;
        }
        delete[] data;
        data = tmp;
        cap *= 2;
    }

    void swap(const Vector &other) noexcept
    {
        std::swap(this->data, other.data);
        std::swap(this->size, other.size);
        std::swap(this->cap, other.cap);
    }

public:
    Vector() : size(0), cap(2)
    {
        data = new T[cap];
    }

    Vector(const Vector &other) : size(other.size), cap(other.cap)
    {
        data = new T[cap];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
        // Can be enhanced by adding a try ~> catch block
    }

    Vector &operator=(Vector &other)
    {
        if (this != &other)
        {
            Vector copy(other);
            this->swap(copy);
        }
        return *this;
    }

    ~Vector()
    {
        delete[] data;
    }

    void push_back(const T &elem)
    {
        if (size >= cap)
            resize();
        data[size++] = elem;
    }

    // TASK 2 ~~> Adds functions
    void clear()
    {
        size = 0;
        // we do not do more, because now we see the old values as junk and will just overwrite them when adding new data
    }

    bool insertAt(const size_t index, const T &value)
    {
        if (index >= size)
            return false;

        this->push_back(0);
        size++;
        for (size_t i = size - 1; i > index; --i)
            data[i] = data[i - 1];

        data[index] = value;

        return true;
    }

    bool eraseAt(const size_t index)
    {
        if (index >= size)
            return false;

        for (size_t i = index; i < size - 1; i++)
            data[i] = data[i + 1];
        size--;

        return true;
    }
};
int main()
{
    int x;
    Vector<int> v1;

    while (std::cin >> x && x != -1)
    {
        v1.push_back(x);
    }

    return 0;
}
