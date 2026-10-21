#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_41_data_1DB84[];
extern u8 lbl_41_data_3E50[];
void fn_41_2D038(void* self, u32 a, s32 b, void* c, void* d);
}

class emSubBase {
public:
    virtual ~emSubBase();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
};

struct ArgPair {
    u32* ptr;
    void* val;
};

extern "C" void* fn_41_65604(void* self, void* owner) {
    *reinterpret_cast<u8**>(self) = lbl_41_data_1DB84;
    void* c = *(void**)(*(u8**)((u8*)owner + 0xd8) + 0xc0);
    ArgPair arg;
    u32 hdr[2];
    hdr[0] = 1;
    hdr[1] = 0x3a;
    arg.ptr = hdr;
    arg.val = c;
    emSubBase* sub = (emSubBase*)(*(u8**)(*(u8**)((u8*)owner + 0xd8) + 0x80) + 8);
    u32 v = sub->vf7();
    fn_41_2D038((u8*)self + 4, 0, (s16)v, &arg, lbl_41_data_3E50);
    return self;
}
