#include <types.h>
#pragma force_active on

extern "C" void fn_27_845D8(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void* lbl_27_data_25F88[];

class EventManager {
public:
    virtual void dummy();
    virtual void remove(long);
};

extern "C" void* fn_27_D767C(void* self, s32 del) {
    if (self != 0) {
        if ((u8*)self + 0xC != 0 && (u8*)self + 0x1C != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_845D8, 0xC, 3);
        }
        if (self != 0) {
            if (self != 0) {
                s16 id = *(s16*)((u8*)self + 4);
                *(void**)self = lbl_27_data_25F88;
                if (id != -1) {
                    EventManager* mgr = (EventManager*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(),
                        *(s16*)((u8*)self + 4));
                    mgr->remove(*(s16*)((u8*)self + 6));
                }
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
