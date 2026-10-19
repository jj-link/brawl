#include <types.h>
#pragma force_active on

extern "C" {

extern void* lbl_27_bss_B8;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_4FAB4(void*);
void fn_27_50108(void*, void*);
u32 fn_27_38048(void*);
void fn_27_37D7C(void*, void*, s32, s32);
void* fn_8015C1B0(void*, void*);
void fn_8015C144(void*, void*);
void fn_8015BFB4(void*, void*);

class PikWorkA {
public:
    virtual u32 m0(void*);
    virtual void* m1(void*);
};

void fn_27_36768(void* p1, s32 p2, void* p3) {
    PikWorkA* obj = *(PikWorkA**)((char*)p1 + 8);
    void* b = obj->m1(p3);
    void* list1 = *(void**)((char*)b + 0x34);
    void* list2 = *(void**)((char*)b + 0x38);
    void* node = fn_8015C1B0(list1, 0);
    void* next;

    while (node) {
        next = fn_8015C1B0(list1, node);
        if (*(u8*)((char*)node + 0x26) == *(u8*)((char*)b + 0x72)) {
            fn_8015C144(list1, node);
            if (*(u8*)((char*)node + 0x27) == 0) {
                fn_8015BFB4(list2, node);
            }
        }
        node = next;
    }

    if (fn_27_38048(b) == 1) {
        fn_27_37D7C(b, (char*)b + 0x28, 1, 0);
    }

    if (p2 == 0) {
        void* node2 = fn_8015C1B0(list2, 0);
        while (node2) {
            void* next2 = fn_8015C1B0(list2, node2);
            if (*(u8*)((char*)node2 + 0x26) == *(u8*)((char*)b + 0x72)) {
                u16 t = *(u16*)((char*)node2 + 0x1c);
                if (t != 0) {
                    t--;
                    *(u16*)((char*)node2 + 0x1c) = t;
                    if (t == 0) {
                        fn_8015C144(list2, node2);
                        if (!lbl_27_bss_B8) {
                            void* mem = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
                            if (mem)
                                mem = fn_27_4FAB4(mem);
                            lbl_27_bss_B8 = mem;
                        }
                        fn_27_50108(lbl_27_bss_B8, node2);
                    }
                }
            }
            node2 = next2;
        }
    }
}

}
