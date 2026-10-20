#pragma force_active on
typedef int s32;

extern "C" {
void* fn_27_1AFA94(void* p, s32 n) {
    s32 idx = (*(s32*)((char*)p + 8) >> 26) + n;
    if (idx >= 25) {
        idx -= 25;
    }
    return (char*)p + idx * 4 + 12;
}
}
