#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_6248[];
extern char lbl_27_data_1180[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dla__FPv(void*);
void __dl__FPv(void*);
void* fn_27_5AE44(void*, short);
}

struct EvSys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual u32 v6(s16);
};

struct EvMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(s16, s16);
};

struct Event {
    void* vtbl;
    s16 id;
    s16 kind;
    s16 handle;
};

struct Obj {
    void* vtbl;
    void* vtbl4;
    char pad8[12];
    Event event;
    char pad20[4];
    void* array;
};

extern "C" Obj* fn_27_5B39C(Obj* p, s32 flag) {
    if (p) {
        p->vtbl = lbl_27_data_6248;
        p->vtbl4 = lbl_27_data_6248 + 0x34;
        p->event.vtbl = lbl_27_data_6248 + 0x50;
        __dla__FPv(p->array);

        if (&p->event) {
            if (&p->event) {
                s16 id = p->event.id;
                p->event.vtbl = lbl_27_data_1180;
                if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                    ((EvMgr*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), p->event.id))->v3(
                            p->event.kind, p->event.handle);
                }
                p->event.handle = -1;
                p->event.id = -1;
            }
        }

        fn_27_5AE44(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
