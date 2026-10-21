#include <types.h>
#pragma force_active on

extern "C" void fn_27_84198(void* p, int n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);
extern "C" char lbl_27_data_25948[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void* self, long idx);

class EvMgrIface {
public:
    virtual void f0();
    virtual void f1(s32 x);
};

extern "C" void* fn_27_1E43EC(void* self, s32 del) {
    if (self != 0) {
        if ((u8*)self + 0xc != 0 && (u8*)self + 0x1c != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_84198, 0xc, 1);
        }
        if (self != 0 && self != 0) {
            *(void**)self = lbl_27_data_25948;
            if (*(s16*)((u8*)self + 4) != -1) {
                void* inst = getInstance__13soEventSystemFv();
                EvMgrIface* mgr = (EvMgrIface*)getManager__13soEventSystemFl(inst, *(s16*)((u8*)self + 4));
                mgr->f1(*(s16*)((u8*)self + 6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
