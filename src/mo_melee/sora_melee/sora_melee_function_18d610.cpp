#include <types.h>
#pragma force_active on

extern "C" void fn_27_84258(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, s32);
extern "C" unsigned char lbl_27_data_25FD8[];

struct EventManager {
    virtual void unused();
    virtual void call(s16);
};

class soSituationEventObserver;

template <class T, int N>
class soEventUnitWithWorkArea {
public:
    void* vtable;
    s16 managerID;
    s16 eventID;
    u8 data[0x50];
    ~soEventUnitWithWorkArea();
};

template <>
soEventUnitWithWorkArea<soSituationEventObserver, 4>::~soEventUnitWithWorkArea() {
    if ((u8*)this + 0xC != 0 && (u8*)this + 0x1C != 0) {
        __destroy_arr((u8*)this + 0x28, fn_27_84258, 0xC, 4);
    }
    if (this != 0) {
        if (this != 0) {
            vtable = lbl_27_data_25FD8;
            if (managerID != -1) {
                void* system = getInstance__13soEventSystemFv();
                ((EventManager*)getManager__13soEventSystemFl(
                    system, managerID))->call(eventID);
            }
        }
    }
}
