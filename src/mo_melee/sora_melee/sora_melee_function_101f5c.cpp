#include <types.h>
#pragma force_active on

// The element copied by fn_27_101F5C is a 12-byte struct:
//   s32, s32, s16, s16
// The source/destination objects are polymorphic; the accessor lives at
// vtable slot 28 (offset 0x70), after 26 preceding virtual functions.
struct SoElement {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
};

class SoContainer {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual SoElement& at(u32 index);

    SoElement m_e;
};

extern "C" void fn_27_101F5C(SoContainer* dest, u32 srcIndex, u32 dstIndex) {
    dest->at(dstIndex) = dest->at(srcIndex);
}
