#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" char lbl_27_data_44A68[];
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void fn_27_84118(void*, int);
extern "C" void fn_27_A6978(void*, int);
extern "C" void* fn_27_A78FC(void*, short);
extern "C" void* fn_27_A3704(void*, short);
extern "C" void* fn_27_26F0D0(void*, short);
extern "C" void* fn_27_262FCC(void*, int);
extern "C" void __dl__FPv(void*);

class soGimmickEventObserver;
template <class T> struct soEventObserver {
    static char __vt[];
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(s16, s16);
    virtual void slot4();
    virtual void slot5();
    virtual u32 slot6(s16);
};

extern "C" void* fn_27_268674(char* p, int flag) {
    if (p) {
        if (p + 0x57c) {
            if (p + 0x588 && p + 0x598) {
                __destroy_arr(p + 0x5a4, fn_27_84118, 0xc, 8);
            }
            if (p + 0x57c && p + 0x57c) {
                *(void**)(p + 0x57c) = lbl_27_data_44A68;
                if (*(s16*)(p + 0x580) != -1) {
                    soEventSystem* system = soEventSystem::getInstance();
                    system->getManager(*(s16*)(p + 0x580))->eraseUnit(*(s16*)(p + 0x582));
                }
            }
        }
        if (p + 0x414) {
            if (p + 0x54c) {
                __destroy_arr(p + 0x558, fn_27_A6978, 0x24, 1);
            }
            fn_27_A78FC(p + 0x464, -1);
            fn_27_A3704(p + 0x418, -1);
        }
        if (p + 0x364) {
            fn_27_26F0D0(p + 0x368, -1);
        }
        if (p + 0x358 && p + 0x358) {
            s16 id = *(s16*)(p + 0x35c);
            *(void**)(p + 0x358) = (void*)soEventObserver<soGimmickEventObserver>::__vt;
            if (((Object_vptr_0*)soEventSystem::getInstance())->slot6(id) == 1) {
                soEventSystem::getInstance()->getManager(*(s16*)(p + 0x35c))->eraseObserver(*(s16*)(p + 0x35e), *(s16*)(p + 0x360));
            }
            *(s16*)(p + 0x360) = -1;
            *(s16*)(p + 0x35c) = -1;
        }
        fn_27_262FCC(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}