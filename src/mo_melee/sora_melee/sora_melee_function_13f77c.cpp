#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_5B30[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_1DBB60(void*, s16);
extern "C" void fn_27_13F86C(void*, s16);
extern "C" void fn_27_1D81C8(void*, s16);

struct EvSys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual u32 v6(s16 id);
};

struct EvMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(s16 a, s16 b);
};

extern "C" void* fn_27_13F77C(void* p, s32 flag) {
    if (p != nullptr) {
        if ((u32)p + 0x99c != 0 && (u32)p + 0x99c != 0) {
            s16 id = *(s16*)((char*)p + 0x9a0);
            *(void**)((char*)p + 0x99c) = (void*)lbl_27_data_5B30;
            u32 r = ((EvSys*)getInstance__13soEventSystemFv())->v6(id);
            if (r == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((char*)p + 0x9a0));
                mgr->v3(*(s16*)((char*)p + 0x9a2), *(s16*)((char*)p + 0x9a4));
            }
            *(s16*)((char*)p + 0x9a4) = -1;
            *(s16*)((char*)p + 0x9a0) = -1;
        }
        if (p != nullptr) {
            fn_27_1DBB60((char*)p + 0x920, -1);
            fn_27_13F86C((char*)p + 0xcc, -1);
            fn_27_1D81C8(p, 0);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}