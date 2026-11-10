#include <cstring>
#include <types.h>
#pragma force_active on

extern "C" int __cntlzw(unsigned int);

extern "C" u16 fn_801853E0(char* self, void* src, u32 offset, u32 count) {
    char* buf = *(char**)(self + 0xD4);
    if (buf == nullptr) {
        return 0;
    }
    u32 size = *(u16*)(self + 0xF8);
    s32 n = -((s32)(((u32)__cntlzw(size) >> 5) & 1));
    u16 half = (u16)(size / 2 - 1);
    u16 maxLen = (u16)(half & ~n);
    if (offset >= maxLen) {
        return 0;
    }
    u16 avail = maxLen - offset;
    u32 n2 = count;
    if (count > avail) {
        n2 = avail;
    }
    memcpy(buf + ((offset * 2) & 0x1FFFE), src, (n2 * 2) & 0x1FFFE);
    u16 end = (u16)(offset + n2);
    *(u16*)(self + 0xFA) = end;
    *(u16*)(*(char**)(self + 0xD4) + ((end * 2) & 0x1FFFE)) = 0;
    return (u16)n2;
}
