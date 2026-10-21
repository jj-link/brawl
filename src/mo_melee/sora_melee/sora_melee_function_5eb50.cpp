#include <types.h>
#pragma force_active on

class VPad {
public:
    u32 a;
    u32 b;
};

class VObj : public VPad {
public:
    virtual u32 v0(u32, u32, u32, u32, u32, u32);
    virtual u32 v1(u32, u32, u32, u32, u32, u32);
    virtual u32 v2(u32, u32, u32, u32, u32, u32);
    virtual u32 v3(u32, u32, u32, u32, u32, u32);
    virtual u32 v4(u32, u32, u32, u32, u32, u32);
    virtual u32 v5(u32, u32, u32, u32, u32, u32);
    virtual u32 v6(u32, u32, u32, u32, u32, u32);
    virtual u32 v7(u32, u32, u32, u32, u32, u32);
    virtual u32 v8(u32, u32, u32, u32, u32, u32);
    virtual u32 v9(u32, u32, u32, u32, u32, u32);
    virtual u32 v10(u32, u32, u32, u32, u32, u32);
    virtual u32 v11(u32, u32, u32, u32, u32, u32);
    virtual u32 v12(u32, u32, u32, u32, u32, u32);
    virtual u32 v13(u32, u32, u32, u32, u32, u32);
    virtual u32 v14(u32, u32, u32, u32, u32, u32);
    virtual u32 v15(u32, u32, u32, u32, u32, u32);
    virtual u32 v16(u32, u32, u32, u32, u32, u32);
    virtual u32 v17(u32, u32, u32, u32, u32, u32);
    virtual u32 v18(u32, u32, u32, u32, u32, u32);
    virtual u32 v19(u32, u32, u32, u32, u32, u32);
    virtual u32 v20(u32, u32, u32, u32, u32, u32);
    virtual u32 v21(u32, u32, u32, u32, u32, u32);
    virtual u32 v22(u32, u32, u32, u32, u32, u32);
    virtual u32 v23(u32, u32, u32, u32, u32, u32);
    virtual u32 v24(u32, u32, u32, u32, u32, u32);
    virtual u32 v25(u32, u32, u32, u32, u32, u32);
    virtual u32 v26(u32, u32, u32, u32, u32, u32);
    virtual u32 v27(u32, u32, u32, u32, u32, u32);
    virtual u32 v28(u32, u32, u32, u32, u32, u32);
    virtual u32 v29(u32, u32, u32, u32, u32, u32);
    virtual u32 v30(u32, u32, u32, u32, u32, u32);
    virtual u32 v31(u32, u32, u32, u32, u32, u32);
    virtual u32 v32(u32);
};

extern "C" void fn_27_5EB50(void* self, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6) {
    u8* r10 = *(u8**)((u8*)self + 0x3c);
    VObj* obj = *(VObj**)(*(u8**)(r10 + 0xd8) + 4);
    u32 ret = obj->v32(p2);
    ((VObj*)self)->v15(p1, ret, p3, p4, p5, p6);
}
