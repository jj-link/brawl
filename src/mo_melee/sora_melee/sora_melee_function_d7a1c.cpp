#include <types.h>
#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int),
                              unsigned long, unsigned long);
extern "C" void* fn_27_84218(void*, int);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();

struct EventManager {
    virtual void f0();
    virtual void remove(short);
};

extern "C" EventManager* getManager__13soEventSystemFl(void*, long);
extern char lbl_27_data_25F60[];

extern "C" void* fn_27_D7A1C(void* object, s32 deleteFlag) {
    if (object) {
        if ((char*)object + 0x0C && (char*)object + 0x1C) {
            __destroy_arr((char*)object + 0x28,
                          (void (*)(void*, int))fn_27_84218, 12UL, 1UL);
        }

        if (object) {
            if (object) {
                *(void**)object = lbl_27_data_25F60;
                if (*(s16*)((char*)object + 4) != -1) {
                    void* system = getInstance__13soEventSystemFv();
                    getManager__13soEventSystemFl(
                        system, *(s16*)((char*)object + 4))
                        ->remove(*(s16*)((char*)object + 6));
                }
            }
        }

        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
