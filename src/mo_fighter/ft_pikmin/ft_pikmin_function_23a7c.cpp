#include <types.h>
#pragma force_active on

typedef unsigned short Word;

extern "C" void fn_27_1DC5E8(void*, int, void*, Word, Word, Word, unsigned char, int,
                             void*, int, int, int, int, int, int, int);
extern "C" char lbl_113_data_AC20[];

extern "C" void* fn_113_23A7C(void* self, int a2, void* a3, Word a4, Word a5, Word a6,
                              unsigned char a7, int a8, int a9, void* a10, int a11,
                              int a12, int a13) {
    fn_27_1DC5E8(self, a2, a3, a4, a5, a6, a7, a9, a10, 0, 0, 0, 0, a11, a12, a13);
    *reinterpret_cast<void**>(self) = lbl_113_data_AC20;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x40) = a8;
    return self;
}
