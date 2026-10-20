#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" void* fn_27_D9930(void* obj, s32 idx)
{
    char* p = (char*)obj;
    s32 v = *(s32*)(p + 8);
    s32 i = (v >> 27) + idx;
    if (i >= 11) {
        i -= 11;
    }
    return p + i * 0x34 + 0xc;
}
