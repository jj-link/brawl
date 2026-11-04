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
    u8 pad0[0x14];
    void* unk14;
    s16 m18, m1A, m1C;
    u8 pad1E[2];
    void* unk20;
    s16 m24, m26, m28;
};

extern "C" Obj* fn_27_75B6C(Obj* p, s32 flag) {
    if (p != 0) {
        if ((u32)p + 0x20 != 0 && (u32)p + 0x20 != 0) {
            s16 id = p->m24;
            p->unk20 = lbl_27_data_731C;
            u32 r = soEventSystem::getInstance()->getInstanceManager().isContain(id);
            if (r == 1) {
                soEventManager* mgr = soEventSystem::getInstance()->getManager(p->m24);
                mgr->eraseObserver(p->m26, p->m28);
            }
            p->m28 = -1;
            p->m24 = -1;
        }
        if ((u32)p + 0x14 != 0 && (u32)p + 0x14 != 0) {
            s16 id = p->m18;
            p->unk14 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            u32 r = soEventSystem::getInstance()->getInstanceManager().isContain(id);
            if (r == 1) {
                soEventManager* mgr = soEventSystem::getInstance()->getManager(p->m18);
                mgr->eraseObserver(p->m1A, p->m1C);
            }
            p->m1C = -1;
            p->m18 = -1;
        }
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}