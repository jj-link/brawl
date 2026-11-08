#include <types.h>
#include <so/event/so_event_system.h>

#pragma force_active on

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* __dt__21soCollisionAttackPartFv(void*, short);
void* __dt__27soCollisionAttackModuleImplFv(void*, short);
void fn_27_262FCC(void*, int);
void fn_27_26F0D0(void*, short);
void fn_27_37D3C(void*, int);
void fn_27_84118(void*, int);
void fn_27_A3704(void*, short);
void fn_27_A6978(void*, int);
void fn_27_A78FC(void*, short);
extern char lbl_27_data_44A68[];
}

class soCollisionAttackModuleImpl {
public:
    virtual ~soCollisionAttackModuleImpl();
    virtual void fn_27_39AA4();
    virtual void fn_27_39C34();
    virtual void fn_27_39C90();
    virtual void fn_27_39D10();
    virtual void fn_27_39D80();
    virtual void fn_27_39E30();
};

class soGimmickEventObserver;

template <class T>
struct soEventObserver {
    static char __vt[];
};

extern "C" void* fn_27_267F20(void* self, int flag) {
    char* p = (char*)self;
    if (self) {
        if (p + 0x744) {
            if (p + 0x750 && p + 0x760) {
                __destroy_arr(p + 0x76C, fn_27_84118, 0xC, 8);
            }
            if (p + 0x744 && p + 0x744) {
                short id = *(short*)(p + 0x748);
                *(void**)(p + 0x744) = lbl_27_data_44A68;
                if (id != -1) {
                    soEventSystem::getInstance()->getManager(*(short*)(p + 0x748))
                        ->eraseUnit(*(short*)(p + 0x74A));
                }
            }
        }
        if (p + 0x5DC) {
            if (p + 0x714) {
                __destroy_arr(p + 0x720, fn_27_A6978, 0x24, 1);
            }
            fn_27_A78FC(p + 0x62C, -1);
            fn_27_A3704(p + 0x5E0, -1);
        }
        if (p + 0x52C) {
            fn_27_26F0D0(p + 0x530, -1);
        }
        if (p + 0x364) {
            __dt__27soCollisionAttackModuleImplFv(p + 0x488, -1);
            if (p + 0x400) {
                __destroy_arr(p + 0x40C, fn_27_37D3C, 0x78, 1);
            }
            if (p + 0x364) {
                __destroy_arr(p + 0x370,
                              (void (*)(void*, int))__dt__21soCollisionAttackPartFv,
                              0x90, 1);
            }
        }
        if (p + 0x358 && p + 0x358) {
            short id = *(short*)(p + 0x35C);
            *(void**)(p + 0x358) = soEventObserver<soGimmickEventObserver>::__vt;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1) {
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
