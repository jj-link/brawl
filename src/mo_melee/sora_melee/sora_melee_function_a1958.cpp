#pragma force_active on

struct acCmdInterpreterStackData {
    int a;
    int b;
    unsigned char c;
    int d;
    float e;
};

template <typename T>
class soArrayVectorAbstract {
public:
    virtual void slot00();
    virtual T* at(long index);
    virtual void slot08();
    virtual long size();
    void set(long start, const T& value, long count);
};

template <typename T>
void soArrayVectorAbstract<T>::set(long start, const T& value, long countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= size()) {
        count = size() - start;
    }
    for (int i = 0; i < count; ++i) {
        *at(start + i) = value;
    }
}

template class soArrayVectorAbstract<acCmdInterpreterStackData>;
