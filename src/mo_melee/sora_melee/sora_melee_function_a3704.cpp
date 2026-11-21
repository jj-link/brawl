#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_15614[];
extern char lbl_27_data_5B30[];
extern char lbl_27_data_1180[];
void __dl__FPv(void*);
}

class soAnimCmdEventObserver;
template <class T> class soEventObserver {
public:
    static void __vt(int, int);
};

class MainVirtual {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};

struct Obj {
    char pad0[8];
    void* a8;
    void* aC;
    s16 id10;
    s16 f12;
    s16 f14;
    s16 pad16;
    void* a18;
    s16 id1C;
    s16 f1E;
    s16 f20;
    s16 pad22;
    void* a24;
    s16 id28;
    s16 f2A;
    s16 f2C;
};

extern "C" Obj* fn_27_A3704(Obj* p, s32 flag) {
    if (p) {
        *(void**)p = lbl_27_data_15614;
        p->a8 = lbl_27_data_15614 + 0x88;
        p->aC = lbl_27_data_15614 + 0x94;
        p->a18 = lbl_27_data_15614 + 0xA8;
        p->a24 = lbl_27_data_15614 + 0xB8;
        ((MainVirtual*)p)->h();
        if (&p->a24 != 0 && &p->a24 != 0) {
            s16 id = p->id28;
            p->a24 = lbl_27_data_5B30;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1U) {
                soEventSystem::getInstance()->getManager(p->id28)->eraseObserver(p->f2A, p->f2C);
            }
            p->f2C = -1;
            p->id28 = -1;
        }
        if (&p->a18 != 0 && &p->a18 != 0) {
            s16 id = p->id1C;
            p->a18 = lbl_27_data_1180;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1U) {
                soEventSystem::getInstance()->getManager(p->id1C)->eraseObserver(p->f1E, p->f20);
            }
            p->f20 = -1;
            p->id1C = -1;
        }
        if (&p->aC != 0 && &p->aC != 0) {
            s16 id = p->id10;
            p->aC = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1U) {
                soEventSystem::getInstance()->getManager(p->id10)->eraseObserver(p->f12, p->f14);
            }
            p->f14 = -1;
            p->id10 = -1;
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}