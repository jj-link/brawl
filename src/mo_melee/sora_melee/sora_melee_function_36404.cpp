#pragma force_active on

typedef unsigned int u32;
typedef unsigned short u16;

class PikWork {
public:
    virtual void m0();
    virtual void* m1(void*);
};

extern "C" {
extern void* lbl_27_bss_B8;

void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_4FAB4(void*);
void* fn_27_5012C(void*, u16);
u32 fn_27_38048(void*);
void fn_8015C144(void*, void*);
void fn_27_50108(void*, void*);

void fn_27_36404(void* p1, void* p2, void* p3) {
    if (fn_27_38048((*(PikWork**)((char*)p1 + 8))->m1(p3)) == 1) {
        if (!lbl_27_bss_B8) {
            void* mem = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
            if (mem)
                mem = fn_27_4FAB4(mem);
            lbl_27_bss_B8 = mem;
        }
        p2 = fn_27_5012C(lbl_27_bss_B8, *(u16*)((char*)p2 + 0x1e));
    }

    void* obj = (*(PikWork**)((char*)p1 + 8))->m1(p3);
    fn_8015C144(*(void**)((char*)obj + 0x34), p2);

    if (!lbl_27_bss_B8) {
        void* mem = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
        if (mem)
            mem = fn_27_4FAB4(mem);
        lbl_27_bss_B8 = mem;
    }

    fn_27_50108(lbl_27_bss_B8, p2);
}
}
