#include <types.h>
#pragma force_active on

extern "C" {

extern void* lbl_27_bss_B8;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_4FAB4(void*);
void* fn_27_5012C(void*, u16);
u32 fn_27_38048(u32);

class PikWork {
public:
    virtual u32 m0(void*);
    virtual u32 m1(void*);
};

void fn_27_36510(void* p1, void* p2, void* p3) {
    PikWork* obj = *(PikWork**)((char*)p1 + 8);
    void* ptr;
    if (fn_27_38048(obj->m1(p3)) == 1) {
        if (!lbl_27_bss_B8) {
            void* mem = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
            if (mem)
                mem = fn_27_4FAB4(mem);
            lbl_27_bss_B8 = mem;
        }
        ptr = fn_27_5012C(lbl_27_bss_B8, *(u16*)((char*)p2 + 0x1e));
    } else {
        ptr = p2;
    }
    *(s32*)((char*)ptr + 0xc) = -1;
}

}
