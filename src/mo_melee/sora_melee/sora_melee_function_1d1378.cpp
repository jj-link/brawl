#pragma force_active on

typedef long s32;

class soGimmickEventObserver {};

template <class T>
struct soInstanceUnitFullProperty {
    int a;
    int b;
    short c;
    short d;
};

template <class T>
class soArrayVectorAbstract {
public:
    virtual void f0() = 0;
    virtual T& at(s32 index) = 0;
    virtual void f2() = 0;
    virtual s32 size() const = 0;
    void set(s32 start, const T& elm, s32 countArg);
};

template <class T>
void soArrayVectorAbstract<T>::set(s32 start, const T& elm, s32 countArg) {
    s32 count = static_cast<s32>(countArg);
    if (count + start >= this->size())
        count = this->size() - start;
    for (s32 i = 0; i < count; ++i) {
        this->at(start + i) = elm;
    }
}

template void soArrayVectorAbstract<soInstanceUnitFullProperty<soGimmickEventObserver*> >::set(s32, const soInstanceUnitFullProperty<soGimmickEventObserver*>&, s32);
