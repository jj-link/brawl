#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_731C[];

class soAnimCmdEventObserver;
template <class T> struct soEventObserver {
    static void __vt(int, int);
};

extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void __dl__FPv(void*);
extern "C" void __destroy_arr(void*, void (*)(void*, s32), s32, s32);
extern "C" void fn_27_AB510(void*, s32);
extern "C" void fn_27_AB18C(void*, s32);

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

extern "C" void* fn_27_313C08(void* p, s32 flag) {
    if (p != nullptr) {
        if ((u32)p + 0x17C != 0) {
            if ((u32)p + 0x19C != 0 && (u32)p + 0x19C != 0) {
                s16 id = *(s16*)((char*)p + 0x1A0);
                *(void**)((char*)p + 0x19C) = (void*)lbl_27_data_731C;
                u32 r = ((EvSys*)getInstance__13soEventSystemFv())->v6(id);
                if (r == 1) {
                    EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(s16*)((char*)p + 0x1A0));
                    mgr->v3(*(s16*)((char*)p + 0x1A2), *(s16*)((char*)p + 0x1A4));
                }
                *(s16*)((char*)p + 0x1A4) = -1;
                *(s16*)((char*)p + 0x1A0) = -1;
            }
            if ((u32)p + 0x190 != 0 && (u32)p + 0x190 != 0) {
                s16 id = *(s16*)((char*)p + 0x194);
                *(void**)((char*)p + 0x190) =
                    (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
                u32 r = ((EvSys*)getInstance__13soEventSystemFv())->v6(id);
                if (r == 1) {
                    EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(s16*)((char*)p + 0x194));
                    mgr->v3(*(s16*)((char*)p + 0x196), *(s16*)((char*)p + 0x198));
                }
                *(s16*)((char*)p + 0x198) = -1;
                *(s16*)((char*)p + 0x194) = -1;
            }
        }
        if ((char*)p + 0x70 != 0) {
            if ((u32)p + 0x90 != 0 && (u32)p + 0x90 != 0 &&
                (u32)p + 0x90 != 0 && (u32)p + 0x90 != 0) {
                __destroy_arr((void*)((char*)p + 0x9C), fn_27_AB510, 0x10, 8);
            }
            if ((u32)p + 0x70 != 0) {
                __destroy_arr((void*)((char*)p + 0x7C), fn_27_AB18C, 0x14, 1);
            }
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}