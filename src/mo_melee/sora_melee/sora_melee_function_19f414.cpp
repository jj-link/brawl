#pragma force_active on
typedef int s32;

extern "C" s32 fn_27_19F414(void* p) {
    s32 w = *(s32*)((char*)p + 8);
    return ((w >> 19) & 0x1F) << 27 >> 28;
}
