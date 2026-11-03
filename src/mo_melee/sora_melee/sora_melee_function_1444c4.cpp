#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_141954(void* a, void* b, void* c, void* d, u32 e, void* f, void* g, void* h, u32 i);

extern "C" u32 fn_27_1444C4(void* a, void* b, void* c, void* d, u32 e, void* f, void* g, void* h, u8 i) {
    u32 result = 0;

    if (e & 0x1) {
        if (fn_27_141954(a, b, c, d, 0, f, g, h, i) == 1)
            result |= 0x1;
    }
    if (e & 0x2) {
        if (fn_27_141954(a, b, c, d, 1, f, g, h, i) == 1)
            result |= 0x2;
    }
    if (e & 0x4) {
        if (fn_27_141954(a, b, c, d, 2, f, g, h, i) == 1)
            result |= 0x4;
    }
    if (e & 0x8) {
        if (fn_27_141954(a, b, c, d, 3, f, g, h, i) == 1)
            result |= 0x8;
    }
    if (e & 0x10) {
        if (fn_27_141954(a, b, c, d, 4, f, g, h, i) == 1)
            result |= 0x10;
    }
    if (e & 0x20) {
        if (fn_27_141954(a, b, c, d, 5, f, g, h, i) == 1)
            result |= 0x20;
    }
    if (e & 0x40) {
        if (fn_27_141954(a, b, c, d, 6, f, g, h, i) == 1)
            result |= 0x40;
    }
    if (e & 0x80) {
        if (fn_27_141954(a, b, c, d, 7, f, g, h, i) == 1)
            result |= 0x80;
    }
    if (e & 0x100) {
        if (fn_27_141954(a, b, c, d, 8, f, g, h, i) == 1)
            result |= 0x100;
    }
    if (e & 0x200) {
        if (fn_27_141954(a, b, c, d, 9, f, g, h, i) == 1)
            result |= 0x200;
    }
    if (e & 0x400) {
        if (fn_27_141954(a, b, c, d, 10, f, g, h, i) == 1)
            result |= 0x400;
    }
    if (e & 0x800) {
        if (fn_27_141954(a, b, c, d, 11, f, g, h, i) == 1)
            result |= 0x800;
    }
    if (e & 0x1000) {
        if (fn_27_141954(a, b, c, d, 12, f, g, h, i) == 1)
            result |= 0x1000;
    }
    if (e & 0x2000) {
        if (fn_27_141954(a, b, c, d, 13, f, g, h, i) == 1)
            result |= 0x2000;
    }
    if (e & 0x4000) {
        if (fn_27_141954(a, b, c, d, 14, f, g, h, i) == 1)
            result |= 0x4000;
    }
    if (e & 0x8000) {
        if (fn_27_141954(a, b, c, d, 15, f, g, h, i) == 1)
            result |= 0x8000;
    }
    return result;
}