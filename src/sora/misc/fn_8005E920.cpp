#pragma force_active on
#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#include <ec/ec_trace_mgr.h>

extern "C" {
extern char lbl_80453DB8[];
void Destroy__Q34nw4r3g3d6G3dObjFv(nw4r::g3d::G3dObj* obj);
void __dla__FPv(void* p);
void __dl__FPv(void* p);
void __dt__10ecTraceMgrFv(ecTraceMgr* self, int flag);
void __dt__6gfTaskFv(void* self, int flag);
void fn_8001AC98();
void fn_80062734(void* arg0, unsigned int arg1);
void fn_803F0D4C(void* block, void (*destroy)(void*, int));
extern void fn_8005E8B0(void*, int);
extern void* g_ecMgr;
}

struct gfTask {
    char pad0[0x3C];
    void* unk3C;
    char pad40[0xC];
    nw4r::g3d::G3dObj* unk4C;
    nw4r::g3d::G3dObj* unk50;
    char pad54[4];
    void* unk58;
    char pad5C[4];
    void* unk60;
    u32 unk64;
    char pad68[4];
    s32 unk6C;
    char pad70[0x28];
};

extern "C" gfTask* fn_8005E920(gfTask* arg0, s32 arg1) {
    if (arg0 != 0) {
        arg0->unk3C = lbl_80453DB8;
        if (arg0->unk6C != 0) {
            u32 i = 0;
            char* cur = (char*)arg0->unk60;
            while (i <= arg0->unk64) {
                if (*(void**)(cur + 0x7C) != 0) {
                    fn_80062734(cur, 1);
                    *(void**)(cur + 0x7C) = 0;
                }
                i++;
                cur += 0x84;
            }
        }
        arg0->unk6C = 0;
        Destroy__Q34nw4r3g3d6G3dObjFv(arg0->unk4C);
        arg0->unk4C = 0;
        Destroy__Q34nw4r3g3d6G3dObjFv(arg0->unk50);
        arg0->unk50 = 0;
        if (arg0->unk60 != 0) {
            if (arg0->unk60 != 0) {
                __dla__FPv((char*)arg0->unk60 - 0x10);
            }
            arg0->unk60 = 0;
        }
        if (arg0->unk58 != 0) {
            fn_803F0D4C(arg0->unk58, fn_8005E8B0);
            arg0->unk58 = 0;
        }
        fn_8001AC98();
        g_ecMgr = 0;
        __dt__10ecTraceMgrFv((ecTraceMgr*)((char*)arg0 + 0x98), -1);
        __dt__6gfTaskFv(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
