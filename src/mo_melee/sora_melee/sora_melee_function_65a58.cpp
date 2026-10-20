#include <types.h>
#pragma force_active on

extern "C" {
extern void* lbl_27_bss_F8;
extern const float lbl_27_rodata_8F8;
void* fn_27_64A90(void* self);
void fn_27_64B54(void* self, void* arg);
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
}

extern "C" int fn_27_65A58(void* self) {
    float f = *(float*)((char*)self + 0x54);
    if (f < lbl_27_rodata_8F8) {
        if (lbl_27_bss_F8 == 0) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
            if (p != 0) {
                p = fn_27_64A90(p);
            }
            lbl_27_bss_F8 = p;
        }
        fn_27_64B54(lbl_27_bss_F8, (void*)((char*)self + 0x50));
        return 1;
    }
    return 0;
}
