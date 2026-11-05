#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" char lbl_27_data_5B3C[];
extern "C" char lbl_27_data_731C[];
extern "C" char lbl_27_data_1180[];
extern "C" void* fn_27_3994(void*, int);
extern "C" void __dl__FPv(void*);

struct Obj {
    char pad[0x64];
    void* vt64;
    s16 h68, h6a, h6c;
    char pad6e[2];
    void* vt70;
    s16 h74, h76, h78;
    char pad7a[2];
    void* vt7c;
    s16 h80, h82, h84;
};

extern "C" Obj* fn_27_1D81C8(Obj* p, int flag) {
    if (p != 0) {
        if ((u32)p + 0x7c != 0 && (u32)p + 0x7c != 0) {
            s16 id = p->h80;
            p->vt7c = lbl_27_data_5B3C;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == true) {
                soEventManager* mgr = soEventSystem::getInstance()->getManager(p->h80);
                mgr->eraseObserver(p->h82, p->h84);
            }
            p->h84 = -1;
            p->h80 = -1;
        }
        if ((u32)p + 0x70 != 0 && (u32)p + 0x70 != 0) {
            s16 id = p->h74;
            p->vt70 = lbl_27_data_731C;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == true) {
                soEventManager* mgr = soEventSystem::getInstance()->getManager(p->h74);
                mgr->eraseObserver(p->h76, p->h78);
            }
            p->h78 = -1;
            p->h74 = -1;
        }
        if ((u32)p + 0x64 != 0 && (u32)p + 0x64 != 0) {
            s16 id = p->h68;
            p->vt64 = lbl_27_data_1180;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == true) {
                soEventManager* mgr = soEventSystem::getInstance()->getManager(p->h68);
                mgr->eraseObserver(p->h6a, p->h6c);
            }
            p->h6c = -1;
            p->h68 = -1;
        }
        fn_27_3994(p, 0);
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}