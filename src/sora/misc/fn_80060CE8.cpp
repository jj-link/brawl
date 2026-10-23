#include <types.h>
#pragma force_active on

extern "C" void fn_80062954(void*, int, int);

extern "C" void fn_80060CE8(void* p, u32 a, u32 b) {
    u32 idx;
    char* ptr;
    u32 mask = b;
    char* cp = (char*)p;
    if (*(u32*)(cp + 0x6C) != 0) {
        idx = *(u32*)(cp + 0x70);
        ptr = (char*)*(void**)(cp + 0x60) + idx * 0x84;
        if (a & 0xFF000000) {
            mask |= 0xFF000000;
        }
        u32 val = a & mask;
        while (idx <= *(u32*)(cp + 0x74)) {
            if (*(u32*)(ptr + 0x7C) != 0) {
                if ((*(u32*)(ptr + 0x78) & mask) == val) {
                    fn_80062954(ptr, 0, 0);
                }
            }
            idx++;
            ptr += 0x84;
        }
    }
}
