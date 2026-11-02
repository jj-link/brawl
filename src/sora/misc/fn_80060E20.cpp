#include <types.h>
#pragma force_active on

extern "C" void fn_80062954(void*, int, int);

extern "C" void fn_80060E20(void* p, u32 a, u32 b, int c, int d, int e) {
    u32 idx;
    char* ptr;
    char* cp = (char*)p;
    if (*(u32*)(cp + 0x6C) != 0) {
        idx = *(u32*)(cp + 0x70);
        ptr = (char*)*(void**)(cp + 0x60) + idx * 0x84;
        if (a & 0xFF000000) {
            b |= 0xFF000000;
        }
        a &= b;
        if (e == 0) {
            while (idx <= *(u32*)(cp + 0x74)) {
                if (*(u32*)(ptr + 0x7C) != 0) {
                    if ((*(u32*)(ptr + 0x78) & b) == a) {
                        fn_80062954(ptr, c, d);
                    }
                }
                idx++;
                ptr += 0x84;
            }
        } else {
            while (idx <= *(u32*)(cp + 0x74)) {
                if (*(u32*)(ptr + 0x7C) != 0) {
                    if ((*(u32*)(ptr + 0x78) & b) == a) {
                        int id = (*(u32*)(*(char**)(ptr + 0x30) + 0x10) << 16) | (*(u32*)(ptr + 0x2C) & 0xFFFF);
                        if (id == e) {
                            fn_80062954(ptr, c, d);
                        }
                    }
                }
                idx++;
                ptr += 0x84;
            }
        }
    }
}
