#pragma force_active on
#include <types.h>

class soKineticEnergy;

template <class T>
class soInstanceUnitFullProperty {
public:
    u32 data[3];
    soInstanceUnitFullProperty();
    ~soInstanceUnitFullProperty();
};

template <class T, s32 C>
class soArrayVector {
public:
    static unsigned char __vt[];
};

template <class T, u32 C>
class soInstanceManagerFullPropertyVector;

template <class T, u32 C>
struct InstanceManagerHeader {
    void* vtable;
    u8 nullFlag;
    u8 padding[3];
    void* priorityVtable;
    void* attributeVtable;
    void* arrayVtable;
    void* arrayBaseVtable;
    u32 flags;

    InstanceManagerHeader() {
        nullFlag = false;
        priorityVtable =
            soInstanceManagerFullPropertyVector<T, C>::__vt + 0x34;
        vtable = soInstanceManagerFullPropertyVector<T, C>::__vt;
        attributeVtable =
            soInstanceManagerFullPropertyVector<T, C>::__vt + 0x40;
        arrayVtable =
            soArrayVector<soInstanceUnitFullProperty<T>, C>::__vt;
        arrayBaseVtable =
            soArrayVector<soInstanceUnitFullProperty<T>, C>::__vt + 0x48;
        flags &= 0x7FFFF;
    }
};

template <class T, u32 C>
class soInstanceManagerFullPropertyVector : public InstanceManagerHeader<T, C> {
public:
    static unsigned char __vt[];
    soInstanceUnitFullProperty<T> elements[C];
    u8 enabled;

    soInstanceManagerFullPropertyVector(bool);
};

template <class T, u32 C>
soInstanceManagerFullPropertyVector<T, C>::soInstanceManagerFullPropertyVector(bool value)
    : InstanceManagerHeader<T, C>(), enabled(value) {}

template class soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>;
