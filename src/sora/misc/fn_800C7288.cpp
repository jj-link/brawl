#include <types.h>
#pragma force_active on

extern "C" int strcmp(const char*, const char*);
extern char lbl_8059E14C;

struct Text65 {
    char data[65];
};

extern "C" void fn_800C7288(u8* self, u32 arg1, const char* arg2) {
    s32 r = strcmp(arg2, &lbl_8059E14C);
    if ((u32)(-r | r) >> 31) {
        *(Text65*)(self + 0x1A8) = *(const Text65*)arg2;
        *(u32*)(self + 0x380) = arg1;
        *(u8**)(self + 0x384) = self + 0x1A8;
        *(s32*)(self + 0x350) = 9;
    }
}
