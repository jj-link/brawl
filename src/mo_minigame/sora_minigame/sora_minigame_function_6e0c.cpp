#pragma force_active on
#include <gf/gf_task.h>
#include <gf/gf_application.h>
#include <types.h>

extern "C" {
extern const f32 lbl_20_rodata_130[];
extern const char lbl_20_data_7A8[];
extern const char lbl_20_data_800[];
extern char lbl_20_bss_18[];
extern void* lbl_805A0EC8;

gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    gfTask*, const char*, gfTask::Category, int, int, bool);
void fn_802CD0B0(void*);
void fn_20_7608(int*);
void fn_20_46F8(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, int);
void fn_80101378(void*);
void* fn_8027EA20(void*, int, int);
u32 fn_800513BC(void);
}

inline void clearWords(int* p, int* e) {
    do { *p = 0; ++p; } while (p < e);
}

#define W(o) (*(u32*)(self + (o)))
#define B(o) (*(u8*)(self + (o)))
#define F(o) (*(f32*)(self + (o)))

extern "C" void* fn_20_6E0C(void* self_) {
    f32* rod = (f32*)lbl_20_rodata_130;
    u8* self = (u8*)self_;
    int c9 = 9;
    int c10 = 10;
    int c5 = 5;
    int c900 = 900;
    u32 c4 = 4;
    u32 c60 = 60;
    u32 p800 = (u32)lbl_20_data_800;

    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        (gfTask*)self, lbl_20_data_7A8, gfTask::Category_CoinShooter, 14, 13, true);

    W(0x3c) = p800;
    B(0x40) = 0; B(0x41) = 0; B(0x42) = 0; B(0x43) = 0;
    B(0x44) = 0; B(0x45) = 0; B(0x46) = 0; B(0x47) = 0;
    W(0x48) = 0;
    W(0x4c) = 0;
    W(0x50) = 0;
    W(0x54) = 0x2d;
    F(0x58) = rod[0];
    B(0x5c) = 0;
    W(0x60) = 0;
    B(0x64) = 0;
    W(0x68) = 0;
    W(0x6c) = c9;
    W(0x70) = c4;
    W(0x74) = c10;
    W(0x78) = c5;
    B(0x7c) = 0;
    F(0x80) = rod[1];
    F(0x84) = rod[2];
    F(0x88) = rod[3];
    W(0x8c) = 0xe10;
    W(0x90) = 0x1c20;
    W(0x94) = c900;
    W(0x98) = 0x708;
    W(0x9c) = 30;
    W(0xa0) = 0x12c;
    W(0xa4) = 0x4b0;
    B(0xa8) = 0; B(0xa9) = 0;
    W(0xac) = 0; W(0xb0) = 0; W(0xb4) = 0;
    B(0xb8) = 0;
    W(0xbc) = 0x12c;
    W(0xc0) = c900;
    F(0xc4) = rod[4];
    F(0xc8) = rod[5];
    W(0xcc) = c60;
    W(0xd0) = c60;
    W(0xd4) = c10;
    W(0xd8) = 8;
    W(0xdc) = 6;
    W(0xe0) = c5;
    W(0xe4) = c4;
    W(0xe8) = 3;
    W(0xec) = 1;
    W(0xf0) = 30;
    W(0xf4) = 180;
    W(0xf8) = 900;
    W(0xfc) = 2400;
    F(0x100) = rod[6];
    F(0x104) = rod[7];
    B(0x108) = 3;
    B(0x109) = 10;
    B(0x10a) = 5;
    B(0x10b) = 3;
    B(0x10c) = 1;
    B(0x10d) = 6;
    B(0x10e) = 10;
    B(0x10f) = 10;
    B(0x110) = (u8)c60;
    B(0x111) = 2;
    W(0x114) = 20;
    W(0x118) = 10;
    W(0x11c) = 30;
    W(0x120) = 100;
    W(0x124) = 0;
    W(0x128) = 1;
    B(0x12c) = 0; B(0x12d) = 0; B(0x12e) = 0; B(0x12f) = 0;
    B(0x130) = 0; B(0x131) = 0; B(0x132) = 0; B(0x133) = 0;
    B(0x134) = 1; B(0x135) = 1; B(0x136) = 1; B(0x137) = 1;
    B(0x138) = 1; B(0x139) = 1; B(0x13a) = 1; B(0x13b) = 1;
    W(0x13c) = 3;
    W(0x140) = 3;
    W(0x144) = 3;
    W(0x148) = 3;
    W(0x14c) = 3;
    W(0x150) = 3;
    W(0x154) = 3;
    W(0x158) = 3;
    W(0x15c) = 3;
    W(0x160) = 3;
    W(0x164) = 3;
    W(0x168) = 3;
    W(0x16c) = 3;
    W(0x170) = 3;
    W(0x174) = 3;
    W(0x178) = 3;
    B(0x17c) = 20;
    B(0x17d) = 45;
    B(0x17e) = 20;
    B(0x17f) = 10;
    B(0x180) = 3;
    B(0x181) = 2;
    B(0x182) = 5;
    B(0x183) = 50;
    B(0x184) = 0;
    F(0x188) = rod[4];
    B(0x18c) = 25;
    B(0x18d) = 75;
    B(0x18e) = 50;
    W(0x190) = 0;
    W(0x194) = 0;
    W(0x198) = 0;
    W(0x19c) = 0;

    fn_802CD0B0(self + 0x1a0);

    F(0x23c) = rod[0];
    W(0x240) = 0;
    W(0x2d0) = 0;
    B(0x2d4) = 0;
    W(0x2d8) = 0;
    W(0x2ec) = 0;
    W(0x2f0) = 0;
    clearWords((int*)(self + 0x2f4), (int*)(self + 0x304));
    W(0x304) = 0;
    W(0x308) = 0;
    W(0x30c) = 0; W(0x310) = 0; W(0x314) = 0; W(0x318) = 0; W(0x31c) = 0;
    W(0x334) = 0;
    W(0x338) = 0;
    __construct_array(self + 0x34c, (void (*)(void*))fn_20_7608,
        (void (*)(void*, int))fn_20_46F8, 4, 3);

    B(0x35b) = 0;
    B(0x35c) = 0;
    B(0x35d) = 3;
    W(0x360) = 0;
    {
        f32 values[3];
        values[0] = rod[0];
        values[1] = rod[0];
        values[2] = rod[0];
        W(0x364) = ((u32*)values)[0];
        W(0x368) = ((u32*)values)[1];
        W(0x36c) = ((u32*)values)[2];
    }
    B(0x370) = 0;
    B(0x371) = 0;
    fn_80101378(self + 0x374);

    W(0x378) = 0;
    W(0x37c) = 0x258;
    W(0x380) = 0xffffffff;
    W(0x384) = 0xffffffff;
    F(0x390) = rod[2];
    F(0x394) = rod[8];
    F(0x398) = rod[9];
    clearWords((int*)(self + 0x39c), (int*)(self + 0x3b0));

    W(0x4c0) = 0;
    W(0x4c4) = (u32)fn_8027EA20(lbl_805A0EC8, 0, 0x15);
    W(0x4c8) = 0;
    W(0x4cc) = 0;
    W(0x4d0) = (u32)fn_8027EA20(lbl_805A0EC8, 0, 0x15);
    W(0x4d4) = 0;
    W(0x4d8) = 0;
    W(0x4dc) = (u32)fn_8027EA20(lbl_805A0EC8, 0, 0x15);
    W(0x4e0) = 0;
    W(0x4e4) = 0;
    W(0x4e8) = (u32)fn_8027EA20(lbl_805A0EC8, 0, 0x15);
    W(0x4ec) = 0; W(0x4f0) = 0; W(0x4f4) = 0; W(0x4f8) = 0;
    W(0x4fc) = 0x80000000;

    W(0x2dc) = 0; W(0x2e0) = 0; W(0x2e4) = 0; W(0x2e8) = 0;
    B(0x358) = 0;
    B(0x33c) = 0; W(0x340) = 0;
    B(0x359) = 0; B(0x33d) = 0; W(0x344) = 0;
    B(0x35a) = 0; B(0x33e) = 0; W(0x348) = 0;
    W(0x320) = 0;
    B(0x428) = 0; B(0x429) = 0; B(0x42a) = 0; B(0x42b) = 0; B(0x42c) = 0; B(0x42d) = 0;
    W(0x324) = 0;
    B(0x42e) = 0; B(0x42f) = 0; B(0x430) = 0; B(0x431) = 0; B(0x432) = 0; B(0x433) = 0;
    W(0x328) = 0;
    B(0x434) = 0; B(0x435) = 0; B(0x436) = 0; B(0x437) = 0; B(0x438) = 0; B(0x439) = 0;
    W(0x32c) = 0;
    B(0x43a) = 0; B(0x43b) = 0; B(0x43c) = 0; B(0x43d) = 0; B(0x43e) = 0; B(0x43f) = 0;
    W(0x330) = 0;
    B(0x440) = 0; B(0x441) = 0; B(0x442) = 0; B(0x443) = 0; B(0x444) = 0; B(0x445) = 0;
    W(0x244) = 0;
    W(0x248) = 0;
    W(0x24c) = 0;
    W(0x250) = 0;
    W(0x254) = 0;
    W(0x258) = 0;
    W(0x25c) = 0;
    W(0x260) = 0;
    W(0x264) = 0;
    W(0x268) = 0;
    W(0x26c) = 0;
    W(0x270) = 0;
    W(0x274) = 0;
    W(0x278) = 0;
    W(0x27c) = 0;
    W(0x280) = 0;
    W(0x284) = 0;
    W(0x288) = 0;
    W(0x28c) = 0;
    W(0x290) = 0;
    W(0x294) = 0;
    W(0x298) = 0;
    W(0x29c) = 0;
    W(0x2a0) = 0;
    W(0x2a4) = 0;
    W(0x2a8) = 0;
    W(0x2ac) = 0;
    W(0x2b0) = 0;
    W(0x2b4) = 0;
    W(0x2b8) = 0;
    W(0x2bc) = 0;
    W(0x2c0) = 0;
    W(0x2c4) = 0;
    W(0x2c8) = 0;
    W(0x2cc) = 0;

    u32 value = fn_800513BC();
    B(0x388) = 0;
    F(0x38c) = rod[0];
    W(0x68) = value / 10;
    g_gfApplication->m_114.add((gfCallBack*)lbl_20_bss_18);

    return self;
}
