#include <types.h>
#pragma force_active on

extern "C" void fn_8015C144(void* a, void* b);
extern "C" void fn_8015BFB4(void* a, void* b);

struct Arg0 {
    u8 pad_0000[0x5018];
    u8* unk5018;
};

struct Arg1 {
    u8 pad_0000[0x0C];
    s32 unkC;
    u8 pad_0010[0x40 - 0x10];
    s32 unk40;
};

extern "C" s32 fn_80164908(Arg0* arg0, Arg1* arg1) {
    u8* temp = arg0->unk5018 + arg1->unk40 * 0x1C;
    fn_8015C144(temp, arg1);
    fn_8015BFB4(temp + 0xC, arg1);
    arg1->unkC = 3;
    return 1;
}
