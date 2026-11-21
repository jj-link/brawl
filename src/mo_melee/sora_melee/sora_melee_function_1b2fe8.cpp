#include <types.h>
#pragma force_active on
class wnPikminPikmin;
class soNullableInterface {
public:
    virtual bool isNull() const = 0;
};
template <class T>
class soArrayFixed : public soNullableInterface {
public:
    virtual bool isNull() const { return false; }
    virtual T& at(long index) = 0;
    virtual const T& at(long index) const = 0;
    virtual long size() const = 0;
    virtual bool isEmpty() const { return this->size() == 0; }
    virtual ~soArrayFixed() { }
};
template <class T>
class soArrayVectorAbstract : public soArrayFixed<T> {
public:
    virtual void set(long start, const T& elm, long count);
};
template <>
void soArrayVectorAbstract<wnPikminPikmin*>::set(long start, wnPikminPikmin* const& elm, long count) {
    int c = count;
    if (c + start >= this->size())
        c = this->size() - start;
    for (long i = 0; i < c; i++)
        this->at(start + i) = elm;
}
