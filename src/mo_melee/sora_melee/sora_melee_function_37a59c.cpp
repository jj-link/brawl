#include <so/event/so_event_system.h>
#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_731C[];
extern "C" void __dl__FPv(void*);

class soAnimCmdEventObserver;
template <class T> struct soEventObserver {
    static void __vt(int, int);
};

struct Obj {
    u8 pad0[0x6C];
    void* unk6C;
    s16 m70, m72, m74;
    u8 pad76[2];
    void* unk78;
    s16 m7C, m7E, m80;
};

extern "C" Obj* fn_27_37A59C(Obj* p, s32 flag) {
    if (p != 0) {
        if ((u32)p + 0x58 != 0) {
            if ((u32)p + 0x78 != 0 && (u32)p + 0x78 != 0) {
                s16 id = p->m7C;
                p->unk78 = lbl_27_data_731C;
                u32 r = soEventSystem::getInstance()->getInstanceManager().isContain(id);
                if (r == 1) {
                    soEventManager* mgr = soEventSystem::getInstance()->getManager(p->m7C);
                    mgr->eraseObserver(p->m7E, p->m80);
                }
                p->m80 = -1;
                p->m7C = -1;
            }
            if ((u32)p + 0x6C != 0 && (u32)p + 0x6C != 0) {
                s16 id = p->m70;
                p->unk6C = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
                u32 r = soEventSystem::getInstance()->getInstanceManager().isContain(id);
                if (r == 1) {
                    soEventManager* mgr = soEventSystem::getInstance()->getManager(p->m70);
                    mgr->eraseObserver(p->m72, p->m74);
                }
                p->m74 = -1;
                p->m70 = -1;
            }
        }
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}
