#include <types.h>
#pragma force_active on

class Class_C80 {
public:
    virtual void fn_27_FEE4();
    virtual int* fn_27_FF68(int);
    virtual void fn_27_FFAC();
    virtual int fn_27_FFF0();
};

struct Holder {
    Class_C80* obj;
    int pad;
    void* vtable;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_4FAB4(void*);
extern "C" void fn_27_50190(void*, int);
extern "C" unsigned char lbl_27_data_57E8[];
extern void* lbl_27_bss_B8;

extern "C" Holder* fn_27_55FD0(Holder* self, int flag) {
    void* mgr;
    if (self) {
        self->vtable = lbl_27_data_57E8;
        for (int i = 0; i < self->obj->fn_27_FFF0(); i++) {
            if (*self->obj->fn_27_FF68(i) != -1) {
                if (lbl_27_bss_B8 == 0) {
                    void* p = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
                    if (p != 0)
                        p = fn_27_4FAB4(p);
                    lbl_27_bss_B8 = p;
                }
                mgr = lbl_27_bss_B8;
                fn_27_50190(mgr, *self->obj->fn_27_FF68(i));
                *self->obj->fn_27_FF68(i) = -1;
            }
        }
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}