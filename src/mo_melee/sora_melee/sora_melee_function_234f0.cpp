#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" void* fn_27_252D0(void*, short);
extern "C" void __dl__FPv(void*);
extern char lbl_27_data_1180[];

class soAnimCmdEventObserver;
template <class T> class soEventObserver {
public:
    static void __vt(int, int);
};

struct Posture {
    char pad[0x44];
    void* vt44;
    s16 h48, h4a, h4c;
    char pad4e[2];
    void* vt50;
    s16 h54, h56, h58;
};

extern "C" Posture* __dt__19soPostureModuleImplFv(Posture* p, s32 flag) {
    if (p != 0) {
        if ((char*)p + 0x50 != 0 && (char*)p + 0x50 != 0) {
            s16 id = p->h54;
            p->vt50 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == true) {
                soEventManager* mgr = soEventSystem::getInstance()->getManager(p->h54);
                mgr->eraseObserver(p->h56, p->h58);
            }
            p->h58 = -1;
            p->h54 = -1;
        }
        if ((char*)p + 0x44 != 0 && (char*)p + 0x44 != 0) {
            s16 id = p->h48;
            p->vt44 = lbl_27_data_1180;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == true) {
                soEventManager* mgr = soEventSystem::getInstance()->getManager(p->h48);
                mgr->eraseObserver(p->h4a, p->h4c);
            }
            p->h4c = -1;
            p->h48 = -1;
        }
        fn_27_252D0(p, 0);
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}