#include <so/event/so_event_system.h>
#include <types.h>
#pragma force_active on
extern "C" u8 lbl_27_data_7BE0[];
extern "C" void __dl__FPv(void*);
class soAnimCmdEventObserver;
template <class T> struct soEventObserver { static void __vt(int, int); };
namespace matching {
class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_6A3D8();
    virtual void fn_27_6A4BC();
    virtual void fn_27_6A51C();
    virtual void fn_27_6A5E0();
    virtual void fn_27_6A640();
    virtual void fn_27_6A660();
    u32 m4;
    void* v8;
    s16 mC, mE, m10, m12;
};
}
extern "C" matching::soNullable* fn_27_6A3D8(matching::soNullable* p, s32 flag) {
    if (p) {
        *(void**)p = lbl_27_data_7BE0;
        p->v8 = lbl_27_data_7BE0 + 0x1C8;
        p->fn_27_6A51C();
        if ((u32)p + 8 != 0 && (u32)p + 8 != 0) {
            s16 id = p->mC;
            p->v8 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1) {
                soEventManager* mgr = soEventSystem::getInstance()->getManager(p->mC);
                mgr->eraseObserver(p->mE, p->m10);
            }
            p->m10 = -1;
            p->mC = -1;
        }
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}
