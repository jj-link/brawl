#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_26D10[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void* p);

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

extern "C" void* fn_27_27D1CC(void* p, s32 flags) {
    if (p) {
        if (p) {
            if (p) {
                s16 id = *(s16*)((char*)p + 4);
                *(void**)p = (void*)lbl_27_data_26D10;
                if (((EvSys*)getInstance__13soEventSystemFv())->v6(id) == 1) {
                    ((EvMgr*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(),
                        *(s16*)((char*)p + 4)))->v3(
                        *(s16*)((char*)p + 6), *(s16*)((char*)p + 8));
                }
                *(s16*)((char*)p + 8) = -1;
                *(s16*)((char*)p + 4) = -1;
            }
        }
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
