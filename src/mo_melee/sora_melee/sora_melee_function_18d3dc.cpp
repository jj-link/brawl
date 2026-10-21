#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_844D8(void*, int);
extern "C" char lbl_27_data_260C8[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class EventManager {
public:
    virtual void unused();
    virtual void remove(int);
};

extern "C" void* fn_27_18D3DC(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0xc != 0 && (u8*)self + 0x1c != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_844D8, 0xc, 2);
        }
        if (self && self) {
            s16 f = *(s16*)((u8*)self + 4);
            *(void**)self = lbl_27_data_260C8;
            if (f != -1) {
                EventManager* mgr = (EventManager*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), *(s16*)((u8*)self + 4));
                mgr->remove(*(s16*)((u8*)self + 6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
