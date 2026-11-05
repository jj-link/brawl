#include <so/event/so_event_system.h>
#include <types.h>
#pragma force_active on
extern "C" char lbl_27_data_731C[];
extern "C" void __dl__FPv(void*);
class soAnimCmdEventObserver;
template <class T> struct soEventObserver { static void __vt(int, int); };
struct Obj {
    u8 pad0[0x3c];
    void* unk3C;
    s16 m40, m42, m44;
    u8 pad46[2];
    void* unk48;
    s16 m4C, m4E, m50;
};
extern "C" Obj* fn_27_36A100(Obj* p, s32 flag) {
    if (p != 0) {
        if ((u32)p + 0x28 != 0) {
            if ((u32)p + 0x48 != 0 && (u32)p + 0x48 != 0) {
                s16 id = p->m4C;
                p->unk48 = lbl_27_data_731C;
                u32 r = soEventSystem::getInstance()->getInstanceManager().isContain(id);
                if (r == 1) {
                    soEventManager* mgr = soEventSystem::getInstance()->getManager(p->m4C);
                    mgr->eraseObserver(p->m4E, p->m50);
                }
                p->m50 = -1;
                p->m4C = -1;
            }
            if ((u32)p + 0x3c != 0 && (u32)p + 0x3c != 0) {
                s16 id = p->m40;
                p->unk3C = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
                u32 r = soEventSystem::getInstance()->getInstanceManager().isContain(id);
                if (r == 1) {
                    soEventManager* mgr = soEventSystem::getInstance()->getManager(p->m40);
                    mgr->eraseObserver(p->m42, p->m44);
                }
                p->m44 = -1;
                p->m40 = -1;
            }
        }
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}