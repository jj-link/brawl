#include <types.h>
#pragma force_active on

extern "C" void* fn_27_840D8(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

class soTurnEventObserver;
template <class T> class soEventUnitWrapper;

template <> class soEventUnitWrapper<soTurnEventObserver> {
public:
    virtual void dummy();
    ~soEventUnitWrapper();
    s16 managerID;
    s16 eventID;
};

extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

struct EventManager {
    virtual void fn0();
    virtual void fn1(s16);
};

inline soEventUnitWrapper<soTurnEventObserver>::~soEventUnitWrapper() {
    if (managerID != -1) {
        void* system = getInstance__13soEventSystemFv();
        ((EventManager*)getManager__13soEventSystemFl(system, managerID))->fn1(eventID);
    }
}

extern "C" void* fn_27_1A8EB0(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0xC != 0 && (u8*)self + 0x1C != 0) {
            __destroy_arr((u8*)self + 0x28, (void (*)(void*, int))fn_27_840D8, 0xC, 8);
        }
        if (self) {
            ((soEventUnitWrapper<soTurnEventObserver>*)self)->~soEventUnitWrapper();
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
