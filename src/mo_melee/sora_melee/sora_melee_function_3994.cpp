#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_488[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void* p);
extern "C" void __dt__6gfTaskFv(void*, int);

class soAnimCmdEventObserver;
template <class T> struct soEventObserver {
    static void __vt(int, int);
};

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

extern "C" void* fn_27_3994(void* p, s32 flag) {
    if (p != nullptr) {
        if ((u32)p + 0x54 != 0 && (u32)p + 0x54 != 0) {
            s16 id = *(s16*)((char*)p + 0x58);
            *(void**)((char*)p + 0x54) = (void*)lbl_27_data_488;
            u32 r = ((EvSys*)getInstance__13soEventSystemFv())->v6(id);
            if (r == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((char*)p + 0x58));
                mgr->v3(*(s16*)((char*)p + 0x5A), *(s16*)((char*)p + 0x5C));
            }
            *(s16*)((char*)p + 0x5C) = -1;
            *(s16*)((char*)p + 0x58) = -1;
        }
        if ((u32)p + 0x48 != 0 && (u32)p + 0x48 != 0) {
            s16 id = *(s16*)((char*)p + 0x4C);
            *(void**)((char*)p + 0x48) = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
            u32 r = ((EvSys*)getInstance__13soEventSystemFv())->v6(id);
            if (r == 1) {
                EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(s16*)((char*)p + 0x4C));
                mgr->v3(*(s16*)((char*)p + 0x4E), *(s16*)((char*)p + 0x50));
            }
            *(s16*)((char*)p + 0x50) = -1;
            *(s16*)((char*)p + 0x4C) = -1;
        }
        __dt__6gfTaskFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}