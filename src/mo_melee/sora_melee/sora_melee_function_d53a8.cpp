#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void __dl__FPv(void*);
extern char lbl_27_data_21024[];
}

struct EvSys {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual unsigned f6(s16);
};

struct EvMgr {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(s16, s16);
};

extern "C" void* fn_27_D53A8(void* p, s32 flag) {
    if (p != nullptr) {
        s16 id = *(s16*)((char*)p + 4);
        *(void**)p = (void*)lbl_27_data_21024;
        EvSys* sys = (EvSys*)getInstance__13soEventSystemFv();
        unsigned result = sys->f6(id);
        if (result == 1) {
            EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((char*)p + 4));
            mgr->f3(*(s16*)((char*)p + 6), *(s16*)((char*)p + 8));
        }
        *(s16*)((char*)p + 8) = -1;
        *(s16*)((char*)p + 4) = -1;
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
