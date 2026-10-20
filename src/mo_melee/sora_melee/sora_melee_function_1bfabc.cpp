#pragma force_active on
typedef int s32;

extern "C" void* fn_27_1BFABC(void* object, s32 index) {
    s32 packed = *(s32*)((char*)object + 0x18);
    s32 adjusted = (packed >> 26) + index;
    if (adjusted >= 0x12)
        adjusted -= 0x12;
    return (char*)object + adjusted * 12 + 0x1C;
}
