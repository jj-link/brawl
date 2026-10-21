#include <types.h>
#pragma force_active on

extern "C" void fn_27_84558(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void* getInstance__13soEventSystemFv();

class EventManager {
public:
    virtual void unused();
    virtual void remove(long);
};

extern "C" EventManager* getManager__13soEventSystemFl(void*, long);
extern "C" char lbl_27_data_22D70[];

class soCollisionCatchEventObserver {
    u8 data[0x0C];
};

template <class T, int N>
class soEventUnitWithWorkArea {
public:
    u8 data[0x34];
    ~soEventUnitWithWorkArea();
};

template <class T, int N>
soEventUnitWithWorkArea<T, N>::~soEventUnitWithWorkArea() {
    u8* self = (u8*)this;

    if (self + 0x0C != 0) {
        if (self + 0x1C != 0) {
            __destroy_arr(self + 0x28, fn_27_84558, 0x0C, 1);
        }
    }

    if (this != 0) {
        if (this != 0) {
            s16 managerId = *(s16*)(self + 0x04);
            *(void**)self = lbl_27_data_22D70;

            if (managerId != -1) {
                void* system = getInstance__13soEventSystemFv();
                EventManager* manager = getManager__13soEventSystemFl(
                    system, *(s16*)(self + 0x04));
                manager->remove(*(s16*)(self + 0x06));
            }
        }
    }
}

template class soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>;
