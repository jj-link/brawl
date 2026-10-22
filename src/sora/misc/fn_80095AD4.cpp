#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

extern "C" void fn_80095AD4(void* arg0, s32 arg1, u32 arg2) {
    u8* self = (u8*)arg0;
    if (arg1 != 0) {
        if (self[0xD] == 0) {
            self[0xCA] = 0;
            return;
        }
        s32 n = *(s32*)(self + 4);
        *(s32*)(self + 0xE4) = 0;
        s32 i;
        s32 idx;
        s32 k;
        idx = 0;
        i = 0;
        for (k = n; k > 0; k--) {
            u8* elem = (u8*)(*(u32**)(*(u8**)self + i));
            if (arg2 == *(u32*)(elem + 0x1A0)) {
                *(s32*)(self + 0xE4) = idx;
                break;
            }
            i += 4;
            idx++;
        }
        if (idx == *(s32*)(self + 4)) {
            self[0xCA] = 0;
            return;
        }
    }
    self[0xCA] = arg1;
}
