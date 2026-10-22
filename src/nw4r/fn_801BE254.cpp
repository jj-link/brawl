#include <types.h>
#pragma force_active on

extern "C" void fn_801C0AD4(void* object);
extern "C" void fn_801BF178(void* object, float scale);
extern "C" void fn_801D0E70(void* a, s32 b, s32 c);
extern "C" void fn_801D1120(void* p);
extern float lbl_805A34E0;

extern "C" void fn_801BE254(void* self, s32 arg1, s32 arg2, s32 arg3) {
    char* p = (char*)self;
    *(s32*)(p + 0xc8) = arg2;
    fn_801C0AD4(p + 0x18);
    fn_801BF178(self, lbl_805A34E0);
    *(s32*)(p + 0xa0) = 0;
    fn_801D0E70(*(void**)(p + 0xdc), arg1, arg3);
    fn_801D1120(*(void**)(p + 0xdc));
    *(u8*)(p + 0x32) = 1;
}
