#include <types.h>
#pragma force_active on
static inline void* get(char* entry, u32 low) {
    if (*(u8**)(entry + 0x1c) != 0) {
        s8 flag = *(s8*)(entry + 0x11);
        u32 clz = __cntlzw((u32)(flag - 1));
        s8 isByte = (s8)(clz >> 5);
        u8* data = *(u8**)(entry + 0x1c);
        u32 val;
        if (isByte != 0) {
            val = data[low * *(u32*)(entry + 0x20)];
        } else {
            val = *(u16*)(data + low * *(u32*)(entry + 0x20));
        }
        return *(char**)(entry + 0x24) + *(s32*)(entry + 0x28) * (s32)val;
    }
    return 0;
}
static inline s32 impl(void* arg0, u32 arg1) {
    char* entry;
    u8* obj = (u8*)arg0;
    u32 shift = *(u32*)(obj + 0x30);
    u32 low = arg1 & ((u32)-1 >> shift);
    entry = *(char**)(obj + 0x34) + (arg1 >> (0x20 - shift)) * 0x30;
    void* p = get(entry, low);
    if (p != 0) return *(s32*)p;
    return 0;
}
extern "C" s32 fn_802D569C(void* arg0, u32 arg1) {
    return impl(arg0, arg1);
}
