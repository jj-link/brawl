#include <types.h>
#pragma force_active on

struct ListObj {
    virtual void v0();
    virtual int* at(int i);
    virtual void v2();
    virtual int size();
};

struct Holder {
    ListObj* m_obj;
    u8 unk4;
    u8 unk5;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_4FAB4(void* manager);
extern "C" void fn_27_50330(void* manager, int selection);
extern void* lbl_27_bss_B8;

extern "C" void fn_27_560F0(Holder* self) {
    void* mgr;
    for (int i = 0; i < self->m_obj->size(); i++) {
        if (*self->m_obj->at(i) != -1) {
            if (lbl_27_bss_B8 == NULL) {
                void* p = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
                if (p != NULL) {
                    p = fn_27_4FAB4(p);
                }
                lbl_27_bss_B8 = p;
            }
            mgr = lbl_27_bss_B8;
            fn_27_50330(mgr, *self->m_obj->at(i));
        }
    }
    self->unk4 = 0;
    self->unk5 = 0;
}
