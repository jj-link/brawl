#include <types.h>
#pragma force_active on

// The element copied by fn_27_104B24 is a 12-byte struct:
//   s32, s32, s16, s16
// The source/destination objects are polymorphic; the accessor lives at
// vtable slot 28 (offset 0x70).
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
    virtual SoElement& at(u32 index) = 0;

    SoElement m_e;
};

extern "C" void fn_27_104B24(SoContainer* self, u32 srcIndex, u32 dstIndex) {
    SoElement& src = self->at(srcIndex);
    SoElement& dst = self->at(dstIndex);
    dst.unk0 = src.unk0;
    dst.unk4 = src.unk4;
    dst.unk8 = src.unk8;
    dst.unkA = src.unkA;
}
