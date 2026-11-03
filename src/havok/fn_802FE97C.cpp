#include <types.h>
#pragma force_active on

class Class_802FE97C_Vf {
public:
    virtual u32 vf0(void* a, void* b, void* c, void* d, void* e);
};

extern "C" void* fn_802FE97C(u8* self, u8* rec, u32 arg2) {
    Class_802FE97C_Vf* sub = *(Class_802FE97C_Vf**)(*(u8**)(self + 0xC) + 4);
    u32 ret = sub->vf0(*(void**)(self + 0xC), *(void**)self, *(void**)(self + 4), *(void**)(self + 8), *(void**)(rec + 8));
    if ((s8)(ret >> 24) != 0 && rec[0] != 0) {
        return rec + rec[3];
    }
    if (rec[0] == 0) {
        return rec + rec[3];
    }
    u8* base = *(u8**)(*(u8**)(self + 0xC));
    void (*fp)(void*, u32, u32) = *(void (**)(void*, u32, u32))(base + rec[1] * 0x34 + 0x1698);
    fp(rec, arg2, *(u32*)(self + 0x10));
    return rec;
}
