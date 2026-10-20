#pragma force_active on
typedef unsigned int u32;

class wnPikminPikmin;

template <typename T>
class soArrayFixed {
public:
    virtual ~soArrayFixed();
    virtual void slot1();
    virtual void slot2();
    virtual u32 size() const;
    bool isEmpty() const;
};

template <typename T>
bool soArrayFixed<T>::isEmpty() const {
    return size() == 0;
}

template class soArrayFixed<wnPikminPikmin*>;
