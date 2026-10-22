#include <types.h>
#pragma force_active on

class soKineticEnergy {};

class Member {
public:
    virtual void vf0();
    virtual void* get(s32 index);
    virtual void vf2();
    virtual s32 count();
};

class AttributeResult {
public:
    s16 attr;

private:
    AttributeResult(const AttributeResult&);
};

template <typename T>
class soInstanceUnitFullProperty {
public:
    AttributeResult getAttribute() const;
};

template <typename T>
class soArray {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void push(T p);
};

class soInstanceAttribute {
public:
    s16 mask;
};

template <typename T, int N>
class soInstanceManagerFullPropertyVector {
public:
    u8 pad[0x10];
    Member mem;

    void getAttributeArray(const soInstanceAttribute& attr, soArray<T*>& arr);
};

void soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>::getAttributeArray(const soInstanceAttribute& attr, soArray<soKineticEnergy**>& arr) {
    s32 count = mem.count();
    for (s32 i = 0; i < count; i++) {
        s16 kind = ((const soInstanceUnitFullProperty<soKineticEnergy*>*)mem.get(i))->getAttribute().attr;
        if (kind & attr.mask) {
            soKineticEnergy* p = (soKineticEnergy*)mem.get(i);
            arr.push(&p);
        }
    }
}
