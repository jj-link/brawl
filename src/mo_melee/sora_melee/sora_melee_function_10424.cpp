#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" u8 lbl_27_data_E14[];
extern "C" char lbl_27_data_1180[];
extern "C" void __dl__FPv(void*);

class soAnimCmdEventObserver;
template <class T> struct soEventObserver {
    static void __vt(int, int);
};

namespace matching {
class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_10424();
    virtual void fn_27_10614();
    virtual void fn_27_10914();
    virtual void fn_27_10994();
    virtual void fn_27_10A4C();
    virtual void fn_27_10B14();
};
}

struct ObjData {
    void* v0;
    u32 m4;
};
struct Obj : ObjData {
    virtual void slot0();
    virtual void slot1();
    virtual void isNull();
    virtual void fn_27_10424();
    virtual void fn_27_10614();
    virtual void fn_27_10914();
    virtual void fn_27_10994();
    virtual void fn_27_10A4C();
    virtual void fn_27_10B14();
    void* vC;
    s16 m10, m12, m14, pad16;
    void* v18;
    s16 m1C, m1E, m20, pad22;
};

extern "C" Obj* fn_27_10424(Obj* p, s32 flag) {
    if (p) {
        *(void**)((u8*)p + 8) = lbl_27_data_E14;
        *(void**)p = lbl_27_data_E14 + 8;
        p->vC = lbl_27_data_E14 + 0x104;
        p->v18 = lbl_27_data_E14 + 0x114;
        p->fn_27_10914();
        if ((char*)p + 0x18 && (char*)p + 0x18) {
            s16 id = p->m1C;
            p->v18 = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == true) {
                soEventManager* mgr = soEventSystem::getInstance()->getManager(p->m1C);
                mgr->eraseObserver(p->m1E, p->m20);
            }
            p->m20 = -1;
            p->m1C = -1;
        }
        if ((char*)p + 0xC && (char*)p + 0xC) {
            s16 id = p->m10;
            p->vC = lbl_27_data_1180;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == true) {
                soEventManager* mgr = soEventSystem::getInstance()->getManager(p->m10);
                mgr->eraseObserver(p->m12, p->m14);
            }
            p->m14 = -1;
            p->m10 = -1;
        }
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}
