#include <types.h>
#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void* fn_27_A068C(void* p);
void fn_27_A0B58(void* self, void* conv, s32 frame, s32 val);
extern void* lbl_27_bss_2B78;
}

extern "C" void fn_27_9A96C(void* self, u32 index) {
    if (lbl_27_bss_2B78 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x140, 2);
        if (p != 0) {
            p = fn_27_A068C(p);
        }
        lbl_27_bss_2B78 = p;
    }
    char* table = *(char**)((char*)self + 0x120);
    fn_27_A0B58(lbl_27_bss_2B78, *(void**)(table + (index << 3)), (s32)*(u16*)(table + (index << 3) + 4), (s32)self);
}
