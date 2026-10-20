#include <types.h>
#pragma force_active on

class VObj {
public:
    virtual void* v0();
    virtual void* v1(u32 x);
    virtual void* v2();
    virtual void* v3();
};

extern "C" u32 fn_27_41C40(void* a, void* b, u32 c, u32 d, u32 e, u32 f);

extern "C" u32 fn_27_43528(u8* self, u32 a, u32 b) {
    VObj* obj = *(VObj**)(self + 0x58);
    void* p = obj->v1(b);
    u32 r = fn_27_41C40(p, self + 0x38, *(u32*)(self + 0x30), a, b, *(u32*)(self + 0x34));
    *(u32*)(self + 0x34) += r;
    return r;
}
