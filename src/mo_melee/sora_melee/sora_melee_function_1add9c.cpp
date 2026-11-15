#include <types.h>
#include <so/so_instance_unit.h>
#pragma force_active on

class soKineticEnergy;

template <>
class soInstanceUnitFullProperty<soKineticEnergy*> : public soInstanceUnit<soKineticEnergy*> {
public:
    soAttributeFlag getAttribute() const;
};

class ArrayVector {
public:
    virtual void v0();
    virtual void v1();
    virtual soInstanceUnitFullProperty<soKineticEnergy*>* slot2(s32);
};

class Outer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 size();

    u8 m_pad[0xC];
    ArrayVector m_arrayVector;

    s32 find(s32 id) {
        if (id <= -1)
            return -1;
        s32 n = size();
        for (s32 i = 0; i < n; ++i) {
            if (id == m_arrayVector.slot2(i)->m_id)
                return i;
        }
        return -1;
    }
};

extern "C" soAttributeFlag fn_27_1ADD9C(Outer* self, s32 id) {
    s32 i = self->find(id);
    if (i < 0) {
        return soAttributeFlag();
    } else {
        return self->m_arrayVector.slot2(i)->getAttribute();
    }
}
