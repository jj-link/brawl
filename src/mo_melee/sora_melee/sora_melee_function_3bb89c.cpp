#include <types.h>
#pragma force_active on

extern unsigned char lbl_27_bss_7B0C[];
extern void* lbl_27_bss_F0;

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_5BCD0(void*);
extern "C" unsigned int fn_27_5BEA8(void*);
extern "C" s32 fn_27_30FACC(void* a, u32 b, s32 c, void* d, u32 e);

class VObjA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual s32 v16();
};

class VObjB {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void setIt(u32 x);
};

extern "C" {
void fn_27_3BB89C(void* unused, void* self) {
    if (lbl_27_bss_F0 == 0) {
        void* s = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (s != 0) {
            s = fn_27_5BCD0(s);
        }
        lbl_27_bss_F0 = s;
    }
    if (fn_27_5BEA8(lbl_27_bss_F0) != 0) {
        char* a = *(char**)((char*)self + 0xd8);
        VObjA* b = *(VObjA**)(a + 0x70);
        s32 r = b->v16();
        if (fn_27_30FACC(lbl_27_bss_7B0C, 0, r, self, 1) == 0x112) {
            char* c = *(char**)((char*)self + 0xd8);
            VObjB* d = *(VObjB**)(c + 0x64);
            d->setIt(0x22000010);
        }
    }
}
}
