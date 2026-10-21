#include <types.h>
#pragma force_active on

extern "C" void* fn_27_84118(void* p, int size);
extern "C" char lbl_27_data_44A68[];
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), unsigned long size, unsigned long count);
extern "C" void __dl__FPv(void* p);
extern "C" void* getInstance__13soEventSystemFv(void);
extern "C" void* getManager__13soEventSystemFl(void* self, long idx);

class EvMgrBase {
public:
    virtual void v0(void);
    virtual void f1(s32 a);
};

extern "C" void* fn_27_290AE0(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0xc != 0 && (u8*)self + 0x1c != 0) {
            __destroy_arr((u8*)self + 0x28, (void (*)(void*, int))fn_27_84118, 0xc, 9);
        }
        if (self != 0 && self != 0) {
            *(void**)self = lbl_27_data_44A68;
            if (*(s16*)((u8*)self + 4) != -1) {
                void* inst = getInstance__13soEventSystemFv();
                EvMgrBase* mgr = (EvMgrBase*)getManager__13soEventSystemFl(inst, *(s16*)((u8*)self + 4));
                mgr->f1(*(s16*)((u8*)self + 6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
