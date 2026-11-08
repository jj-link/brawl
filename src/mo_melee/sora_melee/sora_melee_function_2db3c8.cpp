#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_731C[];
class soAnimCmdEventObserver;
template <class T> struct soEventObserver {
    static void __vt(int, int);
};
extern "C" void fn_27_AB510(void* p, s32 n);
extern "C" void fn_27_AB18C(void* p, s32 n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, s32), u32 size, u32 count);
extern "C" void __dl__FPv(void* p);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

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

extern "C" void* fn_27_2DB3C8(char* p, s32 flag) {
    if (p != nullptr) {
        if ((u32)p + 0x110 != 0) {
            if ((u32)p + 0x130 != 0 && (u32)p + 0x130 != 0) {
                s16 r31 = *(s16*)(p + 0x134);
                *(void**)(p + 0x130) = lbl_27_data_731C;
                u32 r = ((EvSys*)getInstance__13soEventSystemFv())->v6(r31);
                if (r == 1) {
                    EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(s16*)(p + 0x134));
                    mgr->v3(*(s16*)(p + 0x136), *(s16*)(p + 0x138));
                }
                *(s16*)(p + 0x138) = -1;
                *(s16*)(p + 0x134) = -1;
            }
            if ((u32)p + 0x124 != 0 && (u32)p + 0x124 != 0) {
                s16 r31b = *(s16*)(p + 0x128);
                *(void**)(p + 0x124) = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
                u32 r2 = ((EvSys*)getInstance__13soEventSystemFv())->v6(r31b);
                if (r2 == 1) {
                    EvMgr* mgr2 = (EvMgr*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(s16*)(p + 0x128));
                    mgr2->v3(*(s16*)(p + 0x12A), *(s16*)(p + 0x12C));
                }
                *(s16*)(p + 0x12C) = -1;
                *(s16*)(p + 0x128) = -1;
            }
        }
        if ((u32)p + 0x48 != 0) {
            if ((u32)p + 0x68 != 0 && (u32)p + 0x68 != 0 && (u32)p + 0x68 != 0 && (u32)p + 0x68 != 0) {
                __destroy_arr(p + 0x74, fn_27_AB510, 0x10, 6);
            }
            if (p + 0x48 != nullptr) {
                __destroy_arr(p + 0x54, fn_27_AB18C, 0x14, 1);
            }
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
