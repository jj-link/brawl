#include <types.h>
#include <so/event/so_event_system.h>

#pragma force_active on

extern "C" char lbl_27_data_731C[];
extern "C" void __destroy_arr(void*, void (*)(void*, s32), s32, s32);
extern "C" void fn_27_AB18C(void*, s32);
extern "C" void fn_27_AB510(void*, s32);
extern "C" void __dl__FPv(void*);

class soAnimCmdEventObserver;
template <class T>
struct soEventObserver {
    static void __vt(int, int);
};

struct Object {
    char pad0[0xA4];
    void* observerVtable;
    s16 observerManageID;
    s16 observerUnitID;
    s16 observerSendID;
    char padAE[2];
    void* eventVtable;
    s16 eventManageID;
    s16 eventUnitID;
    s16 eventSendID;
};

extern "C" Object* fn_27_379AA0(Object* p, s32 flag) {
    if (p != 0) {
        if ((u32)p + 0x90 != 0) {
            if ((u32)p + 0xB0 != 0 && (u32)p + 0xB0 != 0) {
                s16 id = p->eventManageID;
                p->eventVtable = (void*)lbl_27_data_731C;

                soEventSystem* system = soEventSystem::getInstance();
                if (system->m_instanceManager.isContain(id) == true) {
                    soEventManager* manager =
                        soEventSystem::getInstance()->getManager(p->eventManageID);
                    manager->eraseObserver(p->eventUnitID, p->eventSendID);
                }

                p->eventSendID = -1;
                p->eventManageID = -1;
            }

            if ((u32)p + 0xA4 != 0 && (u32)p + 0xA4 != 0) {
                s16 id = p->observerManageID;
                p->observerVtable =
                    (void*)soEventObserver<soAnimCmdEventObserver>::__vt;

                soEventSystem* system = soEventSystem::getInstance();
                if (system->m_instanceManager.isContain(id) == true) {
                    soEventManager* manager =
                        soEventSystem::getInstance()->getManager(p->observerManageID);
                    manager->eraseObserver(p->observerUnitID, p->observerSendID);
                }

                p->observerSendID = -1;
                p->observerManageID = -1;
            }
        }

        if ((char*)p + 0x14 != 0) {
            if ((u32)p + 0x34 != 0 && (u32)p + 0x34 != 0 &&
                (u32)p + 0x34 != 0 && (u32)p + 0x34 != 0) {
                __destroy_arr((char*)p + 0x40, fn_27_AB510, 0x10, 2);
            }

            if ((u32)p + 0x14 != 0) {
                __destroy_arr((char*)p + 0x20, fn_27_AB18C, 0x14, 1);
            }
        }

        if (flag > 0) {
            __dl__FPv(p);
        }
    }

    return p;
}
