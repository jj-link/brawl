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

extern "C" void* fn_27_33D848(void* p, s32 flag) {
    if (p != nullptr) {
        if ((u32)p + 0xDC != 0) {
            if ((u32)p + 0xFC != 0 && (u32)p + 0xFC != 0) {
                s16 id = *(s16*)((char*)p + 0x100);
                *(void**)((char*)p + 0xFC) = (void*)lbl_27_data_731C;
                u32 r = ((EvSys*)getInstance__13soEventSystemFv())->v6(id);
                if (r == 1) {
                    EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(s16*)((char*)p + 0x100));
                    mgr->v3(*(s16*)((char*)p + 0x102), *(s16*)((char*)p + 0x104));
                }
                *(s16*)((char*)p + 0x104) = -1;
                *(s16*)((char*)p + 0x100) = -1;
            }
            if ((u32)p + 0xF0 != 0 && (u32)p + 0xF0 != 0) {
                s16 id = *(s16*)((char*)p + 0xF4);
                *(void**)((char*)p + 0xF0) =
                    (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
                u32 r = ((EvSys*)getInstance__13soEventSystemFv())->v6(id);
                if (r == 1) {
                    EvMgr* mgr = (EvMgr*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(s16*)((char*)p + 0xF4));
                    mgr->v3(*(s16*)((char*)p + 0xF6), *(s16*)((char*)p + 0xF8));
                }
                *(s16*)((char*)p + 0xF8) = -1;
                *(s16*)((char*)p + 0xF4) = -1;
            }
        }
        if ((char*)p + 0x48 != 0) {
            if ((u32)p + 0x68 != 0 && (u32)p + 0x68 != 0 &&
                (u32)p + 0x68 != 0 && (u32)p + 0x68 != 0) {
                __destroy_arr((void*)((char*)p + 0x74), fn_27_AB510, 0x10, 2);
            }
            if ((u32)p + 0x48 != 0) {
                __destroy_arr((void*)((char*)p + 0x54), fn_27_AB18C, 0x14, 1);
            }
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
