#include <types.h>
#pragma force_active on

class soKineticEnergy;
class soAttributeFlag {
public:
    soAttributeFlag() : m_mask(0) {}
    ~soAttributeFlag() {}
    s16 m_mask;
};

template <typename T>
class soInstanceUnitFullProperty {
public:
    T m_element;
    s32 m_id;
    soAttributeFlag getAttribute() const;
};

class Object_vptr_10 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual soInstanceUnitFullProperty<soKineticEnergy*>& slot2(s32 index);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4();

    u32 unk4;
    u32 unk8;
    u32 unkC;
    Object_vptr_10 m_inner;

    s32 find(s32 key) {
        if (key <= -1)
            return -1;
        s32 n = slot4();
        for (s32 i = 0; i < n; ++i) {
            if (key == m_inner.slot2(i).m_id)
                return i;
        }
        return -1;
    }
};

extern "C" soAttributeFlag fn_27_1AF16C(Object_vptr_0* self, s32 key) {
    s32 idx = self->find(key);
    if (idx < 0)
        return soAttributeFlag();
    return self->m_inner.slot2(idx).getAttribute();
}
