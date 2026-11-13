#pragma force_active on
#include <types.h>

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* __dt__23soEventManageModuleImplFv(void*, short);
void fn_27_840D8(void*, int);
void fn_27_84358(void*, int);
void fn_27_84198(void*, int);
void fn_27_845D8(void*, int);
void fn_27_84458(void*, int);
void fn_27_84398(void*, int);
void fn_27_50588(void*, int);
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
extern char lbl_27_data_21D78[];
extern char lbl_27_data_25948[];
extern char lbl_27_data_25F88[];
extern char lbl_27_data_26028[];
extern char lbl_27_data_26050[];
}

class soTurnEventObserver;
class soLinkEventObserver;

template <class T>
struct soEventUnitWrapper {
    static char __vt[];
};

template <class T>
struct soInstanceUnitFullProperty {
    char d[12];
    ~soInstanceUnitFullProperty();
};

struct LinkArray {
    char pad[12];
    soInstanceUnitFullProperty<soLinkEventObserver*> arr[1];
};

struct EventManager {
    virtual void fn0();
    virtual void fn1(short);
};

struct EventUnitSlot3B0 { char pad[0x3B0]; void* vtable; };
struct EventUnitSlot370 { char pad[0x370]; void* vtable; };
struct EventUnitSlot310 { char pad[0x310]; void* vtable; };
struct EventUnitSlot2B4 { char pad[0x2B4]; void* vtable; };
struct EventUnitSlot278 { char pad[0x278]; void* vtable; };
struct EventUnitSlot170 { char pad[0x170]; void* vtable; };
struct EventUnitSlotCC  { char pad[0xCC];  void* vtable; };

extern "C" void* fn_27_36EA84(void* self, int del) {
    char* p = (char*)self;

    if (self) {
        if (p + 0x3B0) {
            if (p + 0x3BC && p + 0x3CC)
                __destroy_arr(p + 0x3D8, fn_27_840D8, 0xC, 6);
            if (p + 0x3B0 && p + 0x3B0) {
                short id = *(short*)(p + 0x3B4);
                ((EventUnitSlot3B0*)p)->vtable =
                    soEventUnitWrapper<soTurnEventObserver>::__vt;
                if (id != -1)
                    ((EventManager*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(short*)(p + 0x3B4)))
                        ->fn1(*(short*)(p + 0x3B6));
            }
        }

        if (p + 0x370) {
            if (p + 0x37C && p + 0x38C)
                __destroy_arr(p + 0x398, fn_27_84358, 0xC, 1);
            if (p + 0x370 && p + 0x370) {
                short id = *(short*)(p + 0x374);
                ((EventUnitSlot370*)p)->vtable = lbl_27_data_21D78;
                if (id != -1)
                    ((EventManager*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(short*)(p + 0x374)))
                        ->fn1(*(short*)(p + 0x376));
            }
        }

        if (p + 0x310) {
            if (p + 0x31C && p + 0x32C)
                __destroy_arr(p + 0x338, fn_27_84198, 0xC, 4);
            if (p + 0x310 && p + 0x310) {
                short id = *(short*)(p + 0x314);
                ((EventUnitSlot310*)p)->vtable = lbl_27_data_25948;
                if (id != -1)
                    ((EventManager*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(short*)(p + 0x314)))
                        ->fn1(*(short*)(p + 0x316));
            }
        }

        if (p + 0x2B4) {
            if (p + 0x2C0 && p + 0x2D0)
                __destroy_arr(p + 0x2DC, fn_27_845D8, 0xC, 4);
            if (p + 0x2B4 && p + 0x2B4) {
                short id = *(short*)(p + 0x2B8);
                ((EventUnitSlot2B4*)p)->vtable = lbl_27_data_25F88;
                if (id != -1)
                    ((EventManager*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(short*)(p + 0x2B8)))
                        ->fn1(*(short*)(p + 0x2BA));
            }
        }

        if (p + 0x278) {
            if (p + 0x284)
                ((LinkArray*)(p + 0x294))->~LinkArray();
            if (p + 0x278 && p + 0x278) {
                short id = *(short*)(p + 0x27C);
                ((EventUnitSlot278*)p)->vtable =
                    soEventUnitWrapper<soLinkEventObserver>::__vt;
                if (id != -1)
                    ((EventManager*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(short*)(p + 0x27C)))
                        ->fn1(*(short*)(p + 0x27E));
            }
        }

        if (p + 0x170) {
            if (p + 0x17C && p + 0x18C)
                __destroy_arr(p + 0x198, fn_27_84458, 0xC, 0x12);
            if (p + 0x170 && p + 0x170) {
                short id = *(short*)(p + 0x174);
                ((EventUnitSlot170*)p)->vtable = lbl_27_data_26028;
                if (id != -1)
                    ((EventManager*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(short*)(p + 0x174)))
                        ->fn1(*(short*)(p + 0x176));
            }
        }

        if (p + 0xCC) {
            if (p + 0xD8 && p + 0xE8)
                __destroy_arr(p + 0xF4, fn_27_84398, 0xC, 0xA);
            if (p + 0xCC && p + 0xCC) {
                short id = *(short*)(p + 0xD0);
                ((EventUnitSlotCC*)p)->vtable = lbl_27_data_26050;
                if (id != -1)
                    ((EventManager*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(short*)(p + 0xD0)))
                        ->fn1(*(short*)(p + 0xD2));
            }
        }

        __dt__23soEventManageModuleImplFv(p + 0xB8, -1);

        if (p && p + 0x14)
            __destroy_arr(p + 0x20, fn_27_50588, 8, 0x13);

        if (del > 0)
            __dl__FPv(self);
    }

    return self;
}
