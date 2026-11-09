#include <types.h>
#pragma force_active on

struct FnDst { u32 a; u32 b; s16 c; s16 d; };
struct Entry { FnDst value; char pad[8]; };

struct InnerObj {
    virtual void v00();
    virtual FnDst* v08(s32);
    virtual void v0c();
    virtual void v10();
    virtual unsigned int v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28();
    virtual void v2c(s32, FnDst*);
    virtual void v30(); virtual void v34();
    virtual void v38();
    char pad04[8];
    Entry entries[1];
};
struct OuterObj {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual s32 v10(); virtual void v14(); virtual void v18();
    char pad04[0xC];
    InnerObj inner;
    inline s32 find(s32 limit) {
        if (limit <= -1) return v10() - 1;
        for (s32 i = 0; i < v10(); ++i) {
            s16 val = inner.v08(i)->d;
            if (val <= -1) return i - 1;
            if (val > limit) return i - 1;
        }
        return v10() - 1;
    }
};

class soKineticEnergy;

template <class T>
struct soInstanceUnitFullProperty {
    u32 m_0;
    s32 m_4;
    s16 m_8;
    s16 m_a;
    soInstanceUnitFullProperty(T const& elm, s32 id, s16 const& attr, s16 p4);
};

template <>
soInstanceUnitFullProperty<soKineticEnergy*>::soInstanceUnitFullProperty(
    soKineticEnergy* const& elm, s32 id, s16 const& attr, s16 p4);

extern "C" s32 fn_27_C8388(void*, s32, s32);

extern "C" s32 fn_27_D8834(OuterObj* self, soKineticEnergy** a, s32 b, s16* c, s16 d) {
    s32 pos = self->v10() - 1;
    if (d >= 0) pos = self->find(d);
    s32 idx = fn_27_C8388(&self->inner, pos, b);
    if (idx >= 0) {
        s16 h = *c;
        soInstanceUnitFullProperty<soKineticEnergy*> result(*a, b, h, d);
        if (self->inner.v14() != 1U && idx >= 0) self->inner.v38();
        self->inner.entries[idx].value = *(FnDst*)&result;
    }
    return idx;
}
