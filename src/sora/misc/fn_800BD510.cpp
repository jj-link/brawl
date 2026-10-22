#pragma force_active on

typedef unsigned int u32;
typedef int s32;

extern "C" void fn_800BD5AC(void);

extern "C" s32 fn_800BD510(void* self, u32 arg1) {
    char* p = (char*)self;
    if (*(s32*)(p + arg1 * 4 + 0xe8c) != 2) {
        *(u32*)(p + *(s32*)(p + 0x12a8) * 4 + 0x10a8) = arg1;
        if (*(s32*)(p + 0x12a8) == 0 && *(s32*)(p + 0x44) >= 2) {
            *(s32*)(p + 0x44) = 6;
            fn_800BD5AC();
            *(u32*)(p + 0x1094) = arg1 & 3;
            *(u32*)(p + 0x1090) = arg1 >> 2;
        }
        *(s32*)(p + 0x12a8) = *(s32*)(p + 0x12a8) + 1;
    }
    return *(s32*)(p + 0x12a8);
}
