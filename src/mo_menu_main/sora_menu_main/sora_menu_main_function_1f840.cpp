#pragma force_active on
#include <types.h>
#include <gf/gf_pad_system.h>
#include <mu/mu_object.h>
struct Menu {
    u8 data[0x668];
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual s32 run(u32);
};
extern "C" {
u32 fn_18_1A58(void*);
u32 fn_18_12E0(void*);
s32 fn_2_20718(void*, u32);
s32 fn_80073D00(void*);
void fn_800B7AA4(void*, s32);
extern void* g_sndSystem;
extern float lbl_2_rodata_920[];
}
extern "C" s32 fn_2_1F840(u8* self) {
    float* c = lbl_2_rodata_920;
    gfPadStatus sp;
    float f;
    s32 st;
    st = *(s32*)(self + 0x664);
    if (st == 0 || (u32)st == 3U) {
        MuObject* obj;
        g_gfPadSystem->getSysPadStatus(fn_18_1A58(self), &sp);
        obj = *(MuObject**)(*(u8**)(self + 0x64c) + 0x1ac);
        if (sp.m_error != 0) {
            f = c[12];
        } else {
            switch (sp.m_controllerType) {
            case 0: f = c[13]; break;
            case 1: f = c[5]; break;
            case 2: f = c[14]; break;
            case 3: f = c[4]; break;
            default: f = c[15]; break;
            }
        }
        if (f >= c[13]) fn_800B7AA4(obj, 4);
    }
    switch (*(s32*)(self + 0x664)) {
    case 0:
        if (fn_2_20718(self, fn_18_12E0(self)) != 0) {
            *(s32*)(self + 0x664) = 4;
            return 1;
        }
        break;
    case 3:
        if (((Menu*)self)->run(fn_18_12E0(self)) != 0) {
            *(s32*)(self + 0x664) = 4;
            return 1;
        }
        break;
    case 2:
        if (fn_80073D00(g_sndSystem) != 0) {
            u8* p = *(u8**)(self + 0x64c);
            float fv;
            *(s32*)(self + 0x664) = 3;
            fv = c[14];
            (*(MuObject**)(p + 0x1ac))->setFrameVisible(fv);
        }
        break;
    case 4:
        if (c[13] == (*(MuObject**)(*(u8**)(self + 0x64c) + 0x1a4))->m_modelAnim->getUpdateRate()) return 3;
        break;
    }
    return 0;
}