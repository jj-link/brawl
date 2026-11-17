#include <types.h>
#include <gf/gf_task.h>
#include <cm/cm_stage_param.h>
#include <cm/cm_controller_default.h>
#include <cm/cm_controller_melee_fixed.h>
#include <sr/sr_common.h>
#pragma force_active on

extern "C" {
void __ct__6gfTaskFPCcQ26gfTask8Categoryiib(gfTask*, const char*, gfTask::Category, int, int, bool);
void __ct__29cmStageParamPausedOffsetRangeFv(void*);
void* fn_8009D2DC();
void* fn_8009F564();
void* fn_800A3764(void*);
void* fn_800A3F70(void*);
void* fn_800A5F70(void*);
void* fn_800A6AD4(void*);
void* fn_800A6598(void*);
void* __ct__21cmMenuFixedControllerFv(void*);
void* fn_800A9760(void*);
void* fn_800A9DCC(void*);
void* __ct__22cmMeleeFixedControllerFv(void*);
void* fn_800AA9F8(void*);
extern char lbl_8059DC20;
extern char lbl_80454BF0[];
extern char lbl_80454E70[];
extern cmStageParam lbl_80455078;
extern cmStageParamPaused lbl_804550B8;
extern cmStageParamFixed lbl_80455108;
extern char __vt__19cmDefaultController[];
extern const f32 lbl_805A1DA0, lbl_805A1DA4, lbl_805A1DA8, lbl_805A1DAC, lbl_805A1DB0, lbl_805A1DB4, lbl_805A1DB8;
}
struct Flags { u8 a:1; u8 b:1; u8 c:1; u8 d:5; };
struct Pair { u32 a, b; };
struct Triple { u32 a, b, c; };
struct FixedCopy { Triple center; f32 fov; Pair angles; };
struct Words11 { Pair a,b,c,d,e; u32 f; };
struct Quad { Pair a, b; };
struct Words18 { Pair a; u32 b; Pair c,d,e; u32 f; Quad range, tail; };
#define BYTE(o) (*(u8*)((char*)self + (o)))
#define S32(o) (*(s32*)((char*)self + (o)))
#define F32(o) (*(f32*)((char*)self + (o)))
#define PTR(o) (*(void**)((char*)self + (o)))

static inline void init_values(gfTask* self) {
    f32 y;
    f32 z = lbl_805A1DA0;
    F32(0x168) = z;
    F32(0x16C) = z;
    BYTE(0x44) &= ~0x20;
    *(Words11*)((char*)self + 0x84) = *(Words11*)&lbl_80455078;
    *(f32*)((char*)self + 0xb0) = *(f32*)((char*)&lbl_80455078 + 0x2c);
    *(f32*)((char*)self + 0xb4) = *(f32*)((char*)&lbl_80455078 + 0x30);
    *(f32*)((char*)self + 0xb8) = *(f32*)((char*)&lbl_80455078 + 0x34);
    *(f32*)((char*)self + 0xbc) = *(f32*)((char*)&lbl_80455078 + 0x38);
    *(f32*)((char*)self + 0xc0) = *(f32*)((char*)&lbl_80455078 + 0x3c);
    F32(0xc4) = *(f32*)&lbl_804550B8;
    *(Words18*)((char*)self + 0xc8) = *(Words18*)((char*)&lbl_804550B8 + 4);
    f32 lo = lbl_805A1DA4;
    f32 hi = lbl_805A1DA8;
    f32 deadLo = lbl_805A1DAC;
    f32 deadHi = lbl_805A1DB0;
    f32 one = lbl_805A1DB4;
    f32 maximum = lbl_805A1DB8;
    f32 x = F32(0xA4) + z;
    y = F32(0xA8) + z;
    f32 f7 = lo + x;
    f32 f6 = hi + x;
    f32 f5 = hi + y;
    f32 f4 = z + y;
    f32 f3 = deadLo + x;
    f32 f2 = deadHi + x;
    f32 f1 = deadHi + y;
    f32 f0 = lo + y;
    *(FixedCopy*)((char*)self + 0x110) = *(FixedCopy*)&lbl_80455108;
    F32(0x128) = lo;
    F32(0x12C) = hi;
    F32(0x130) = hi;
    F32(0x134) = z;
    F32(0x138) = deadLo;
    F32(0x13C) = deadHi;
    F32(0x140) = deadHi;
    F32(0x144) = lo;
    F32(0x170) = z;
    F32(0x174) = z;
    F32(0x178) = z;
    F32(0x17C) = z;
    F32(0x180) = one;
    F32(0x184) = z;
    S32(0x188) = 0;
    F32(0x190) = maximum;
    F32(0x18C) = z;
    F32(0x148) = f7;
    F32(0x14C) = f6;
    F32(0x150) = f5;
    F32(0x154) = f4;
    F32(0x158) = f3;
    F32(0x15C) = f2;
    F32(0x160) = f1;
    F32(0x164) = f0;
}

extern "C" gfTask* fn_8009BE7C(gfTask* self) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, &lbl_8059DC20, gfTask::Category_Camera, 14, 11, true);
    PTR(0x3C) = lbl_80454BF0;
    S32(0x40) = 2;
    BYTE(0x44) = BYTE(0x44) | 0x80;
    BYTE(0x44) &= ~0x40;
    ((Flags*)((char*)self + 0x44))->d = 0;
    BYTE(0x45) = 0;
    __ct__29cmStageParamPausedOffsetRangeFv((char*)self + 0xF0);
    init_values(self);
    PTR(0x7C) = fn_8009D2DC();
    void* p = operator new(8, Heaps::System);
    if (p) {
        *(s32*)p = 0;
        *(void**)((char*)p + 4) = __vt__19cmDefaultController;
    }
    PTR(0x4C) = p;
    *(void**)PTR(0x4C) = gfCameraManager::getManager();
    p = operator new(0x94, Heaps::System);
    if (p) p = fn_800A3764(p);
    PTR(0x54) = p;
    *(void**)PTR(0x54) = gfCameraManager::getManager();
    PTR(0x58) = fn_8009F564();
    *(void**)PTR(0x58) = gfCameraManager::getManager();
    p = operator new(0x24, Heaps::System);
    if (p) {
        *(s32*)p = 0;
        *(void**)((char*)p + 4) = lbl_80454E70;
        *(s32*)((char*)p + 8) = 0;
        *(s32*)((char*)p + 0xC) = 0;
        *(s32*)((char*)p + 0x10) = 0;
        *(s32*)((char*)p + 0x14) = 0;
        *(s32*)((char*)p + 0x18) = 0;
        *(s32*)((char*)p + 0x20) = 1;
    }
    PTR(0x50) = p;
    *(void**)PTR(0x50) = gfCameraManager::getManager();
    p = operator new(0x148, Heaps::System);
    if (p) p = fn_800A3F70(p);
    PTR(0x60) = p;
    *(void**)PTR(0x60) = gfCameraManager::getManager();
    p = operator new(0x148, Heaps::System);
    if (p) p = fn_800A5F70(p);
    PTR(0x64) = p;
    *(void**)PTR(0x64) = gfCameraManager::getManager();
    p = operator new(0x104, Heaps::System);
    if (p) p = fn_800A6AD4(p);
    PTR(0x68) = p;
    *(void**)PTR(0x68) = gfCameraManager::getManager();
    p = operator new(0x28, Heaps::System);
    if (p) p = fn_800A6598(p);
    PTR(0x6C) = p;
    *(void**)PTR(0x6C) = gfCameraManager::getManager();
    p = operator new(0x20, Heaps::System);
    if (p) p = __ct__21cmMenuFixedControllerFv(p);
    PTR(0x70) = p;
    *(void**)PTR(0x70) = gfCameraManager::getManager();
    p = operator new(0x40, Heaps::System);
    if (p) p = fn_800A9760(p);
    PTR(0x74) = p;
    *(void**)PTR(0x74) = gfCameraManager::getManager();
    p = operator new(0x58, Heaps::System);
    if (p) p = fn_800A9DCC(p);
    PTR(0x78) = p;
    *(void**)PTR(0x78) = gfCameraManager::getManager();
    p = operator new(0x8, Heaps::System);
    if (p) p = __ct__22cmMeleeFixedControllerFv(p);
    PTR(0x5C) = p;
    *(void**)PTR(0x5C) = gfCameraManager::getManager();
    p = operator new(0x5C, Heaps::System);
    if (p) p = fn_800AA9F8(p);
    PTR(0x80) = p;
    *(void**)PTR(0x80) = gfCameraManager::getManager();
    S32(0x40) = 14;
    PTR(0x48) = PTR(0x4C);
    BYTE(0x2C) &= ~2;
    return self;
}
