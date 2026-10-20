#pragma force_active on
typedef int s32;

extern "C" void* fn_27_2EAC28(void* p, s32 n) {
    s32 sh = *(s32*)((char*)p + 0x18) >> 29;
    s32 idx = sh + n;
    if (idx >= 3) {
        idx -= 3;
    }
    return (char*)p + idx * 12 + 0x1c;
}
