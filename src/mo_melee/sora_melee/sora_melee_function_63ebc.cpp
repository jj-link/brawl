#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" char lbl_27_data_7310[];
extern "C" char lbl_27_data_731C[];
extern "C" void __dl__FPv(void*);

struct Obj {
    char pad[0xC];
    void* vtC;
    s16 h10, h12, h14;
    char pad16[2];
    void* vt18;
    s16 h1c, h1e, h20;
};

extern "C" Obj* fn_27_63EBC(Obj* p, int flag) {
    if (p != 0) {
        if ((u32)p + 0x18 != 0 && (u32)p + 0x18 != 0) {
            s16 id = p->h1c;
            p->vt18 = lbl_27_data_7310;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == true) {
                soEventManager* mgr = soEventSystem::getInstance()->getManager(p->h1c);
                mgr->eraseObserver(p->h1e, p->h20);
            }
            p->h20 = -1;
            p->h1c = -1;
        }
        if ((u32)p + 0xc != 0 && (u32)p + 0xc != 0) {
            s16 id = p->h10;
            p->vtC = lbl_27_data_731C;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == true) {
                soEventManager* mgr = soEventSystem::getInstance()->getManager(p->h10);
                mgr->eraseObserver(p->h12, p->h14);
            }
            p->h14 = -1;
            p->h10 = -1;
        }
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}