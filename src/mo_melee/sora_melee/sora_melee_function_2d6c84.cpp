#include <types.h>
#pragma force_active on

extern "C" int fn_27_2D6E60(
    int, int, s8, int, void*, void*, void*, int,
    void*, u8, void*, void*, void*, void*, void*, void*, u8);

inline int abs8(s8 x) {
    if (x < 0) return -x;
    return x;
}

inline int horizontal(unsigned int keys) {
    int minus = (keys >> 3) & 1;
    minus = -minus;
    int plus = (keys >> 2) & 1;
    return plus + minus;
}

inline int vertical(unsigned int keys, int* pos, int count) {
    int minus = 0;
    if ((keys & 1) && *pos != 0) minus = 1;
    minus = -minus;

    int plus = 0;
    if ((keys & 2) && *pos != count - 1) plus = 1;
    return plus + minus;
}

extern "C" int fn_27_2D6C84(
    void* arg0, unsigned int arg1, int arg2, int arg3) {
    unsigned char* p = (unsigned char*)arg0;
    char* c = (char*)arg0;
    int result = 0;
    int r30 = (s8)abs8(arg3) - 0x20;

    if (r30 <= 0) p[2] = 0;

    if (fn_27_2D6E60(
            horizontal(arg1), arg2 & 0xC, (s8)arg3, r30,
            c + 0x38, c + 0x20, c + 0x18, *(int*)(c + 0x10),
            c + 1, p[2], c + 0x40, c + 0x48, c + 0x50,
            c + 0x28, c + 0x30, c + 4, p[3])) {
        result = 1;
    }

    int count = *(int*)(c + 0xC);
    if (count > 1) {
        if (fn_27_2D6E60(
                vertical(arg1, (int*)(c + 0x34), count), 0, 0, r30,
                c + 0x34, c + 0x1C, c + 0x14, count,
                c + 1, p[2], c + 0x3C, c + 0x44, c + 0x4C,
                c + 0x24, c + 0x2C, c + 4, p[3])) {
            result = 1;
        }
    }

    if (p[2] < 4) p[2]++;

    if (p[3] < 4 && r30 > 0) {
        p[3]++;
    } else {
        p[3] = 0;
    }

    return result;
}
