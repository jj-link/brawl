#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" char lbl_27_data_731C[];

class soAnimCmdEventObserver;
template <class T> struct soEventObserver {
    static void __vt(int, int);
};

extern "C" void fn_27_AB510(void* p, s32 n);
extern "C" void fn_27_AB18C(void* p, s32 n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, s32), u32 size, u32 count);
extern "C" void __dl__FPv(void* p);

struct EvSys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual u32 v6(s16 id);
};

extern "C" void* fn_27_3738B4(char* p, s32 flag) {
    if (p != nullptr) {
        if ((u32)p + 0x90 != 0) {
            if ((u32)p + 0xB0 != 0 && (u32)p + 0xB0 != 0) {
                s16 r31 = *(s16*)(p + 0xB4);
                *(void**)(p + 0xB0) = lbl_27_data_731C;
                u32 r = ((EvSys*)soEventSystem::getInstance())->v6(r31);
                if (r == 1) {
                    soEventManager* mgr = soEventSystem::getInstance()->getManager(*(s16*)(p + 0xB4));
                    mgr->eraseObserver(*(s16*)(p + 0xB6), *(s16*)(p + 0xB8));
                }
                *(s16*)(p + 0xB8) = -1;
                *(s16*)(p + 0xB4) = -1;
            }
            if ((u32)p + 0xA4 != 0 && (u32)p + 0xA4 != 0) {
                s16 r31b = *(s16*)(p + 0xA8);
                *(void**)(p + 0xA4) = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
                u32 r2 = ((EvSys*)soEventSystem::getInstance())->v6(r31b);
                if (r2 == 1) {
                    soEventManager* mgr2 = soEventSystem::getInstance()->getManager(*(s16*)(p + 0xA8));
                    mgr2->eraseObserver(*(s16*)(p + 0xAA), *(s16*)(p + 0xAC));
                }
                *(s16*)(p + 0xAC) = -1;
                *(s16*)(p + 0xA8) = -1;
            }
        }
        if ((u32)p + 0x14 != 0) {
            if ((u32)p + 0x34 != 0 && (u32)p + 0x34 != 0 && (u32)p + 0x34 != 0 && (u32)p + 0x34 != 0) {
                __destroy_arr(p + 0x40, fn_27_AB510, 0x10, 2);
            }
            if (p + 0x14 != nullptr) {
                __destroy_arr(p + 0x20, fn_27_AB18C, 0x14, 1);
            }
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
