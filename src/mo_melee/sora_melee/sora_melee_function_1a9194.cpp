#include <types.h>
#pragma force_active on

extern "C" void fn_27_84398(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_27_data_26050[];
extern "C" void* getInstance__13soEventSystemFv(void);
extern "C" void* getManager__13soEventSystemFl(void*, long);

class EventManager {
public:
    virtual void slot0();
    virtual void remove(s16);
};

extern "C" void* fn_27_1A9194(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0xc != 0 && (u8*)self + 0x1c != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_84398, 0xc, 0xa);
        }
        if (self != 0 && self != 0) {
            *(void**)self = lbl_27_data_26050;
            if (*(s16*)((u8*)self + 0x4) != -1) {
                void* inst = getInstance__13soEventSystemFv();
                EventManager* mgr = (EventManager*)getManager__13soEventSystemFl(
                    inst, *(s16*)((u8*)self + 0x4));
                mgr->remove(*(s16*)((u8*)self + 0x6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
