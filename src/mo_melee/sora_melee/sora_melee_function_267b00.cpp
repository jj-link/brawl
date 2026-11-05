#include <types.h>
#include <so/event/so_event_system.h>

#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* __dt__18soCollisionHitPartFv(void*, short);
void* __dt__19soCollisionHitGroupFv(void*, short);
void* __dt__21soCollisionAttackPartFv(void*, short);
void* __dt__24soCollisionHitModuleImplFv(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void fn_27_262FCC(void*, int);
void fn_27_26F0D0(void*, short);
void fn_27_37D3C(void*, int);
void fn_27_84118(void*, int);
void fn_27_86D4C(void*, int);
void fn_27_A3704(void*, short);
void fn_27_A6978(void*, int);
void fn_27_A78FC(void*, short);
extern char lbl_27_data_44A68[];
}

class soGimmickEventObserver;
template <class T> struct soEventObserver {
    static char __vt[];
};

extern "C" void* fn_27_267B00(void* self, int flag) {
    char* p = (char*)self;
    if (self) {
        if (p + 0x98C) {
            if (p + 0x998 && p + 0x9A8) {
                __destroy_arr(p + 0x9B4, fn_27_84118, 0xC, 8);
            }
            if (p + 0x98C && p + 0x98C) {
                short id = *(short*)(p + 0x990);
                *(void**)(p + 0x98C) = lbl_27_data_44A68;
                if (id != -1) {
                    soEventSystem::getInstance()->getManager(*(short*)(p + 0x990))->eraseUnit(*(short*)(p + 0x992));
                }
            }
        }
        if (p + 0x824) {
            if (p + 0x95C) {
                __destroy_arr(p + 0x968, fn_27_A6978, 0x24, 1);
            }
            fn_27_A78FC(p + 0x874, -1);
            fn_27_A3704(p + 0x828, -1);
        }
        if (p + 0x6CC) {
            fn_27_26F0D0(p + 0x778, -1);
            if (p + 0x6CC && p + 0x6CC) {
                __destroy_arr(p + 0x6D8, fn_27_86D4C, 0xA0, 1);
            }
        }
        if (p + 0x528) {
            __dt__24soCollisionHitModuleImplFv(p + 0x664, -1);
            if (p + 0x620) {
                __destroy_arr(p + 0x62C, (void (*)(void*, int))__dt__19soCollisionHitGroupFv, 0x38, 1);
            }
            if (p + 0x59C) {
                __destroy_arr(p + 0x5A8, fn_27_37D3C, 0x78, 1);
            }
            if (p + 0x528) {
                __destroy_arr(p + 0x534, (void (*)(void*, int))__dt__18soCollisionHitPartFv, 0x68, 1);
            }
        }
        if (p + 0x364) {
            __dt__27soCollisionAttackModuleImplFv(p + 0x488, -1);
            if (p + 0x400) {
                __destroy_arr(p + 0x40C, fn_27_37D3C, 0x78, 1);
            }
            if (p + 0x364) {
                __destroy_arr(p + 0x370, (void (*)(void*, int))__dt__21soCollisionAttackPartFv, 0x90, 1);
            }
        }
        if (p + 0x358 && p + 0x358) {
            short unitId = *(short*)(p + 0x35C);
            *(void**)(p + 0x358) = soEventObserver<soGimmickEventObserver>::__vt;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(unitId) == 1) {
                soEventSystem::getInstance()->getManager(*(short*)(p + 0x35C))->eraseObserver(*(short*)(p + 0x35E), *(short*)(p + 0x360));
            }
            *(short*)(p + 0x360) = -1;
            *(short*)(p + 0x35C) = -1;
        }
        fn_27_262FCC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
