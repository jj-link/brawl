#include <types.h>
#pragma force_active on
extern "C" void fn_27_842D8(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv(void);
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern char lbl_27_data_25F38[];

class soEventMgrBase {
public:
    virtual void vf0();
    virtual void vfCall(s32 id);
};

extern "C" void* fn_27_D7F8C(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0x0C != 0 && (u8*)self + 0x1C != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_842D8, 0x0C, 1);
        }
        if (self != 0 && self != 0) {
            s16 id = *(s16*)((u8*)self + 0x4);
            *(void**)self = lbl_27_data_25F38;
            if (id != -1) {
                soEventMgrBase* mgr = (soEventMgrBase*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((u8*)self + 0x4));
                mgr->vfCall(*(s16*)((u8*)self + 0x6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
