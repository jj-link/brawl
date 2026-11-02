#include <types.h>
#pragma force_active on

struct Pair { int a; int b; };

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void* fn_27_362C(void* p);
void fn_27_3644(void* a, void* b);
void fn_27_3AD0(int a, int b, int c, int d);
void fn_80011C74(int a);
void fn_8011234C(void* p);
void fn_800DB7A8();
void fn_800FC25C();
void fn_8010F310();
void fn_8010674C(int a, int b);
void fn_27_2A1EC0();
void fn_27_10817C();
extern void* lbl_27_bss_8;
extern Pair lbl_27_rodata_3970;
}

extern "C" void fn_27_23A92C(char* self, u32 flags) {
    if (flags & 0x20) {
        Pair data = lbl_27_rodata_3970;
        if (lbl_27_bss_8 == 0) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x28, 2);
            if (p != 0) {
                p = fn_27_362C(p);
            }
            lbl_27_bss_8 = p;
        }
        fn_27_3644(lbl_27_bss_8, &data);
        fn_27_3AD0(200, 10, 1, 0);
        fn_80011C74(1);
        void* q = __nw__FUlQ25Heaps8HeapType(0x4F8, 2);
        if (q != 0) {
            fn_8011234C(q);
        }
        *(u32*)(self + 0x38) |= 0x20;
    }
    if (flags & 1) {
        fn_800DB7A8();
        *(u32*)(self + 0x38) |= 1;
    }
    if (flags & 2) {
        fn_800FC25C();
        *(u32*)(self + 0x38) |= 2;
    }
    if (flags & 0x40) {
        fn_8010F310();
        *(u32*)(self + 0x38) |= 0x40;
    }
    if (flags & 4) {
        fn_8010674C(1, 1);
        *(u32*)(self + 0x38) |= 4;
    }
    if (flags & 8) {
        fn_27_2A1EC0();
        *(u32*)(self + 0x38) |= 8;
    }
    if (flags & 0x10) {
        fn_27_10817C();
        *(u32*)(self + 0x38) |= 0x10;
    }
}
