#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on

class soGimmickEventObserver;

template <class T>
class soEventObserver {
public:
    static char __vt[];
};

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__24soCollisionHitModuleImplFv(void*, int);
void __dt__19soCollisionHitGroupFv(void*, int);
void __dt__18soCollisionHitPartFv(void*, int);
void fn_27_262FCC(void*, int);
void fn_27_26F0D0(void*, int);
void fn_27_A3704(void*, int);
void fn_27_A78FC(void*, int);
void fn_27_84118(void*, int);
void fn_27_86D4C(void*, int);
void fn_27_A6978(void*, int);
void fn_27_37D3C(void*, int);
extern char lbl_27_data_44A68[];
}

extern "C" void* fn_27_2682A8(void* self, int flag) {
    char* p = (char*)self;
    if (self) {
        if (p + 0x7C8) {
            if (p + 0x7D4 && p + 0x7E4) {
                __destroy_arr(p + 0x7F0, fn_27_84118, 0xC, 8);
            }
            if (p + 0x7C8 && p + 0x7C8) {
                short id = *(short*)(p + 0x7CC);
                *(void**)(p + 0x7C8) = lbl_27_data_44A68;
                if (id != -1) {
                    soEventSystem::getInstance()->getManager(*(short*)(p + 0x7CC))->eraseUnit(*(short*)(p + 0x7CE));
                }
            }
        }
        if (p + 0x660) {
            if (p + 0x798) {
                __destroy_arr(p + 0x7A4, fn_27_A6978, 0x24, 1);
            }
            fn_27_A78FC(p + 0x6B0, -1);
            fn_27_A3704(p + 0x664, -1);
        }
        if (p + 0x508) {
            fn_27_26F0D0(p + 0x5B4, -1);
            if (p + 0x508 && p + 0x508) {
                __destroy_arr(p + 0x514, fn_27_86D4C, 0xA0, 1);
            }
        }
        if (p + 0x364) {
            __dt__24soCollisionHitModuleImplFv(p + 0x4A0, -1);
            if (p + 0x45C) {
                __destroy_arr(p + 0x468, __dt__19soCollisionHitGroupFv, 0x38, 1);
            }
            if (p + 0x3D8) {
                __destroy_arr(p + 0x3E4, fn_27_37D3C, 0x78, 1);
            }
            if (p + 0x364) {
                __destroy_arr(p + 0x370, __dt__18soCollisionHitPartFv, 0x68, 1);
            }
        }
        if (p + 0x358 && p + 0x358) {
            short mgrId = *(short*)(p + 0x35C);
            *(void**)(p + 0x358) = soEventObserver<soGimmickEventObserver>::__vt;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(mgrId) == 1) {
                soEventSystem::getInstance()->getManager(*(short*)(p + 0x35C))
                    ->eraseObserver(*(short*)(p + 0x35E), *(short*)(p + 0x360));
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
