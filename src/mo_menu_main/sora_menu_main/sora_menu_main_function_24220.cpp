#include <types.h>
#pragma force_active on

class sndSystem {
public:
    s32 getBGMId();
};

extern sndSystem* g_sndSystem;
extern "C" void fn_80073F84(void*, int);
extern "C" void fn_2_23D34(void*);

extern "C" {
void fn_2_24220(void* self) {
    u8* p = (u8*)self;
    *(s32*)(p + 0x6b4) = 0;
    *(s32*)(p + 0x6c8) = 0;
    *(s32*)(p + 0x6b8) = 0;
    *(s32*)(p + 0x6bc) = 0;
    *(s32*)(p + 0x6c0) = 0;
    *(s32*)(p + 0x670) = 0;
    *(s32*)(p + 0x6ac) = 0;
    *(s32*)(p + 0x6cc) = 0;
    *(s32*)(p + 0x688) = 0;
    *(u8*)(p + 0x6a8) = 0;
    *(u8*)(p + 0x6a9) = 0;
    *(s32*)(p + 0x680) = 0;
    *(s32*)(p + 0x68c) = 5;
    *(s32*)(p + 0x684) = g_sndSystem->getBGMId();
    fn_80073F84(g_sndSystem, 0);
    fn_2_23D34(self);
}
}
