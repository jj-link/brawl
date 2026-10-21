#include <types.h>
#pragma force_active on

struct Element {
    s32 m_00;
    s32 m_04;
    s32 m_08;
    unsigned m_0C_lo : 4;
    unsigned m_0C_mid : 4;
    unsigned m_0C_hi : 24;
};

class ArrayInterface {
public:
    virtual void f0() = 0;
    virtual Element& at(s32 index) = 0;
    virtual void f2() = 0;
    virtual s32 size() = 0;
};

struct Obj {
    s32 m_00[13];
    s32 m_34;
    s32 m_38;
    s32 m_3C;
    ArrayInterface* m_40;
};

extern "C" s32 fn_27_74A7C(Obj* obj, s32 index) {
    s32 effIndex = index;
    if (index == -1)
        effIndex = obj->m_34;
    if (effIndex < 0 || effIndex >= obj->m_40->size())
        return 0;
    Element& elem = obj->m_40->at(effIndex);
    return elem.m_0C_mid;
}
