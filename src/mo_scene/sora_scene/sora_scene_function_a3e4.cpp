#pragma force_active on
typedef int s32;
typedef unsigned char u8;

extern "C" void exit__6gfTaskFv(void*);
extern "C" void fn_3_468(void*, s32);

extern "C" s32 fn_1_A3E4(u8* self) {
    exit__6gfTaskFv(*(void**)(self + 0x8));
    *(void**)(self + 0x8) = 0;
    fn_3_468(*(void**)(self + 0xC), 1);
    *(void**)(self + 0xC) = 0;
    return 0;
}
