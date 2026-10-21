#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_41_data_119B8[];
extern u8 lbl_41_data_3E50[];
void* fn_41_2D038(void* self, s32 zero, s32 val, s32* args, void* table);
}

class IfaceSub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual s32 f7();
};

extern "C" {
void* fn_41_4CE24(void* self, void* arg) {
    u8* a = (u8*)arg;
    *(u8**)self = lbl_41_data_119B8;
    s32 v = (s32)(*(void**)(*(u8**)(a + 0xd8) + 0xc0));
    s32 buf[4];
    buf[0] = 1;
    buf[1] = 0x16;
    buf[2] = (s32)&buf[0];
    buf[3] = v;
    IfaceSub* sub = (IfaceSub*)((u8*)(*(void**)(*(u8**)(a + 0xd8) + 0x80)) + 8);
    s32 ret = sub->f7();
    fn_41_2D038((u8*)self + 4, 0, (s16)ret, &buf[2], lbl_41_data_3E50);
    return self;
}
}
