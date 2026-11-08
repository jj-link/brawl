#include <types.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <gf/gf_shutdown_manager.h>
#include <mu/mu_object.h>
#pragma force_active on
struct Iface {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10();
    virtual void invoke(void*, void*);
};
extern "C" {
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void fn_800B96E8(void*, s32);
void fn_16_26A4(void*);
void fn_16_44C(void*, void*, void*, void*, void*, void*, void*, s32, s32, s32, s32);
void fn_16_2894(void*);
void fn_16_32E8(void*, u16, u16);
}
extern "C" void fn_16_23D0(void* self, void* a1, s32 a2, char* a3, s32 a4,
                           void* a5, char* a6, s32 a7, s32 a8) {
    s32 r30 = 0;
    nw4r::g3d::ResMdl res;
    if (a5) {
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(a5, *(void**)((u8*)self + 0x8c), a6);
        *(void**)((u8*)self + 0x3f8) = a5;
        res = nw4r::g3d::ResMdl(*(void**)(*(u8**)((u8*)a5 + 0xe8) + 0xe8));
        nw4r::g3d::ResNode node = res.GetResNode(a6);
        if (node.ptr())
            r30 = node.ptr()->m_nodeIndex;
        *(s32*)((u8*)self + 0x3fc) = r30;
    } else {
        ((Iface*)a1)->invoke(*(void**)((u8*)a1 + 0xe4), *(void**)((u8*)self + 0x8c));
    }
    *(void**)((u8*)self + 0xa8) = a1;
    *(s32*)((u8*)self + 0x98) = a2;
    *(void**)((u8*)self + 0x3dc) = a3;
    *(s32*)((u8*)self + 0x3e4) = a4;
    *(s32*)((u8*)self + 0x458) = a7;
    *(s32*)((u8*)self + 0x460) = a8;
    fn_800B96E8((u8*)self + 0xac, (u8)a3);
    fn_16_26A4(self);
    s32 sp8 = *(s32*)((u8*)self + 0x154);
    s32 spC = 0;
    s32 sp10 = 0;
    fn_16_44C((u8*)self + 0x158, *(void**)((u8*)self + 0xa8),
              *(void**)((u8*)self + 0x90), *(void**)((u8*)self + 0x50),
              (u8*)self + 0x54, *(void**)((u8*)self + 0x68),
              *(void**)((u8*)self + 0x6c), 5, sp8, spC, sp10);
    fn_16_2894(self);
    g_gfShutdownManager.unk8.add((gfReturnStatusCallback*)((u8*)self + 0x46c));
    *(s32*)((u8*)self + 0x9c) = 1;
    fn_16_32E8(self, *(u16*)((u8*)self + 0x1ec), *(u16*)((u8*)self + 0x1ee));
    (*(MuObject**)((u8*)self + 0x44))->setFrameNode((float)*(u16*)((u8*)self + 0x1ec));
    MuObject* object = *(MuObject**)((u8*)self + 0x44);
    s32 sum = *(u16*)((u8*)self + 0x1ec) + *(u16*)((u8*)self + 0x1ee);
    s32 flags = 0;
    if (sum > 0) flags |= 2;
    if (sum < (s32)*(u16*)((u8*)self + 0x3d8) - 1) flags |= 1;
    object->setFrameVisible((float)flags);
}