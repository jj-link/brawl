#include <types.h>
#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void* fn_27_A068C(void* p);
void fn_27_A0BD8(void* a, void* b, void* c);
extern void* lbl_27_bss_2B78;
}

extern "C" void fn_27_9A9F4(void* self, u32 index) {
    if (lbl_27_bss_2B78 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x140, 2);
        if (p != 0) {
            p = fn_27_A068C(p);
        }
        lbl_27_bss_2B78 = p;
    }
    char* table = *(char**)((char*)self + 0x120);
    fn_27_A0BD8(lbl_27_bss_2B78, *(void**)(table + (index << 3)), self);
}
