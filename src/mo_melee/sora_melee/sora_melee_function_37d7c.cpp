#include <types.h>
#pragma force_active on

extern "C" {

extern void* lbl_27_bss_B8;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_4FAB4(void*);
void fn_27_50108(void*, void*);
void* fn_8015C1B0(void*, void*);
void fn_8015C144(void*, void*);

void fn_27_37D7C(void* p1, void* p2, s32 p3, u32 p4) {
    void* node = fn_8015C1B0(p2, 0);
    if (p3 == 0) {
        while (node) {
            void* next = fn_8015C1B0(p2, node);
            if (p4 == 1 || *(u8*)((char*)node + 0x26) == *(u8*)((char*)p1 + 0x72)) {
                fn_8015C144(p2, node);
            }
            node = next;
        }
    } else {
        while (node) {
            void* next = fn_8015C1B0(p2, node);
            if (p4 == 1 || *(u8*)((char*)node + 0x26) == *(u8*)((char*)p1 + 0x72)) {
                fn_8015C144(p2, node);
                if (!lbl_27_bss_B8) {
                    void* mem = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
                    if (mem)
                        mem = fn_27_4FAB4(mem);
                    lbl_27_bss_B8 = mem;
                }
                fn_27_50108(lbl_27_bss_B8, node);
            }
            node = next;
        }
    }
}

}