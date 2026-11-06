#pragma force_active on
#include <so/so_instance_unit.h>

class soKineticEnergy;

template <>
class soInstanceUnitFullProperty<soKineticEnergy*> {
public:
    soKineticEnergy* m_element;
    s32 m_id;
    s16 m_attribute;
    s16 m_10;
    soInstanceUnitFullProperty(soKineticEnergy* const&, long, const s16&, s16);
};

class Object_vptr_10 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual soInstanceUnitFullProperty<soKineticEnergy*>* slot2(s32);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(s32, const soInstanceUnitFullProperty<soKineticEnergy*>&);
    virtual void slot12();
    virtual void slot13();
    virtual u32 slot14();
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4();
    virtual void slot5();
    virtual u32 slot6(s32);
    char pad04[0xC];
    Object_vptr_10 inner;
    char pad14[0x2C];
    u8 flag;

    inline s32 find(s32 limit) {
        if (limit <= -1) return slot4();
        s32 n = slot4();
        for (s32 i = 0; i < n; i++) {
            s16 val = inner.slot2(i)->m_10;
            if (val <= -1) return i;
            if (val > limit) return i;
        }
        return n;
    }
};

extern "C" s32 fn_27_2EAD24(Object_vptr_0*);

extern "C" s32 fn_27_2EA50C(Object_vptr_0* self, soKineticEnergy* const& arg1, s32 arg2, const s16& arg3, s16 arg4) {
    if (self->inner.slot14() == 1U) return -1;
    if (self->flag == 0 || arg2 > -1) {
        if (self->slot6(arg2) == 1U) return -1;
    }
    if (self->flag == 0 && arg2 <= -1) {
        s32 result = fn_27_2EAD24(self);
        arg2 = result;
        if (result <= -1) return -1;
    }
    s32 idx = self->find(arg4);
    if (idx < 0) return -1;
    s16 attr = arg3;
    soInstanceUnitFullProperty<soKineticEnergy*> property(arg1, arg2, attr, arg4);
    self->inner.slot11(idx, property);
    return arg2;
}
