#include <types.h>
#pragma force_active on

extern "C" void fn_27_84398(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

class EventManager {
public:
    virtual void unused();
    virtual void remove(s16);
};

extern "C" void* getInstance__13soEventSystemFv();
extern "C" EventManager* getManager__13soEventSystemFl(void*, long);
extern "C" char lbl_27_data_26050[];

struct Event {
    void* vptr;
    s16 id;
    s16 entry;
};

extern "C" void* fn_27_1E46DC(Event* self, s32 del) {
    if (self) {
        if ((u8*)self + 0xC != 0 && (u8*)self + 0x1C != 0) {
            __destroy_arr((u8*)self + 0x28, fn_27_84398, 0xC, 4);
        }
        if (self && self) {
            self->vptr = lbl_27_data_26050;
            if (self->id != -1) {
                void* system = getInstance__13soEventSystemFv();
                EventManager* mgr = getManager__13soEventSystemFl(system, self->id);
                mgr->remove(self->entry);
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
