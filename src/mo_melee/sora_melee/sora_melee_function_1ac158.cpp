#pragma force_active on
typedef int s32;

extern "C" void* fn_27_1AC158(void* p, s32 idx) {
    s32 v = *(s32*)((char*)p + 0x18);
    s32 sh = v >> 27;
    s32 n = sh + idx;
    n = (n >= 11) ? n - 11 : n;
    return (char*)p + (n << 4) + 0x1c;
}
