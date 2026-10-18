#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" u32 fn_114_19B04(char* self, s32 unused, s32 index) {
    char* p = self + ((index - *(s32*)(self + 0x18)) << 2);
    return *(u32*)(p + 0x34);
}
