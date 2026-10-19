#pragma force_active on
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern "C" u32 fn_27_5F890(void*, s8);

extern "C" bool fn_41_12D6C(void* p1, s8 p2) {
    bool result = false;
    if (fn_27_5F890(p1, p2) == 1 || p2 == 0x6b) {
        result = true;
    }
    return result;
}
