#pragma force_active on
#include <types.h>
#include <revolution/OS/OSTime.h>

extern "C" {

void* memset(void* dst, int val, unsigned long size);
s64 OSGetTime();
s64 fn_803F1470(s64 a, s64 b);
void fn_8001B784(int arg0);
void fn_80038570(void*, int);
u8 fn_8020FB50();
void* getManager__15gfCameraManagerFv();
void fn_8001A108(char* self, int arg1);
void fn_80076F30(int snd, float a, float b);
void fn_800513E4(int arg0, void* arg1);
void fn_8004F710(void*);
void fn_8004F884();
void fn_80051BE4();
void fn_80051D78();
void fn_8004F428();
void fn_8004F454();
void fn_80078768(void*);

extern void* g_GameGlobal;
extern int g_sndSystem;
extern void* lbl_805A0098;
extern void* lbl_805A01D8;
extern float lbl_805A1864;

void fn_8004E13C(void* self) {
    char* p;
    char* q;
    int zero;
    int flag;
    int cam;
    s64 res;

    p = *(char**)((char*)self + 0x24);
    memset(p, 0, 0x3CF0);
    memset(*(char**)((char*)self + 0x28), 0, 0x88E0);

    res = fn_803F1470(OSGetTime(), (u32) * (u32*)0x800000F8 >> 2);

    p = *(char**)((char*)self + 0x0);
    *(s64*)(p + 0x20) = res;

    p = *(char**)((char*)g_GameGlobal + 0x24);
    *(u32*)(p + 0x2D0) = *(u32*)(p + 0x2D0) + 1;

    p = *(char**)((char*)self + 0x24);
    p[0x82A] = 1;

    fn_8001B784(1);

    flag = !((((unsigned char) * ((char*)lbl_805A0098 + 0x4C)) >> 6) & 1);
    fn_80038570(lbl_805A0098, flag);

    p = *(char**)((char*)self + 0x24);
    p[0x829] = (u8)(flag == 1);

    if (fn_8020FB50() == 1) {
        p = *(char**)((char*)g_GameGlobal + 0x24);
        *(u8*)(p + 0x838) |= 0x80;
        p = *(char**)((char*)g_GameGlobal + 0x24);
        *(u8*)(p + 0x838) |= 0x40;
    } else {
        p = *(char**)((char*)g_GameGlobal + 0x24);
        p[0x838] &= ~0x80;
        p = *(char**)((char*)g_GameGlobal + 0x24);
        *(u8*)(p + 0x838) &= 0xFFFFFFBF;
    }

    p = *(char**)((char*)g_GameGlobal + 0x24);
    flag = !((((u8) * (p + 0x838)) >> 7) & 1);
    cam = (int)getManager__15gfCameraManagerFv();
    fn_8001A108((char*)cam, flag);

    p = *(char**)((char*)self + 0x24);
    {
        float f = lbl_805A1864;
        p[0x828] = 0x32;
    }

    fn_80076F30(g_sndSystem, 0.5f, 0.5f);

    p = *(char**)((char*)self + 0x24);
    *(u32*)(p + 0x834) = -1;
    *(u32*)(p + 0x830) = -1;

    p = *(char**)((char*)self + 0x24);
    p[0x810] = 2;

    p = *(char**)((char*)self + 0x24);
    *(u32*)(p + 0x81C) = -1;
    *(u32*)(p + 0x818) = -1;

    fn_800513E4(0x1F4, p);

    p = *(char**)((char*)self + 0x24);
    p[0x820] = 1;
    p = *(char**)((char*)self + 0x24);
    p[0x821] = 1;
    p = *(char**)((char*)self + 0x24);
    p[0x822] = 1;
    p = *(char**)((char*)self + 0x24);
    p[0x823] = 1;
    p = *(char**)((char*)self + 0x24);
    p[0x824] = 1;
    p = *(char**)((char*)self + 0x24);
    p[0x825] = 1;
    p = *(char**)((char*)self + 0x24);
    p[0x826] = 1;
    p = *(char**)((char*)self + 0x24);
    p[0x827] = 1;

    p = *(char**)((char*)g_GameGlobal + 0x24);
    *(u32*)(p + 0x268) &= ~1;
    p = *(char**)((char*)g_GameGlobal + 0x24);
    *(u32*)(p + 0x268) &= ~2;
    p = *(char**)((char*)g_GameGlobal + 0x24);
    *(u32*)(p + 0x268) &= ~4;
    p = *(char**)((char*)g_GameGlobal + 0x24);
    *(u32*)(p + 0x268) &= ~8;

    fn_8004F710(p);
    fn_8004F884();
    fn_80051BE4();
    fn_80051D78();
    fn_8004F428();
    fn_8004F454();

    p = *(char**)((char*)self + 0x24);
    memset(p + 0x1528, 0, 0x81);

    p = *(char**)((char*)self + 0x24);
    zero = 0;
    *(u32*)(p + 0x15AC) = zero;
    *(u32*)(p + 0x15B0) = zero;
    *(u32*)(p + 0x15B4) = zero;
    *(u32*)(p + 0x15B8) = zero;
    *(u32*)(p + 0x15BC) = zero;
    *(u32*)(p + 0x15C0) = zero;
    *(u32*)(p + 0x15C4) = zero;
    *(u32*)(p + 0x15C8) = zero;
    *(u32*)(p + 0x15CC) = zero;
    *(u32*)(p + 0x15D0) = zero;
    *(u32*)(p + 0x15D4) = zero;
    *(u32*)(p + 0x15D8) = zero;
    *(u32*)(p + 0x15DC) = zero;
    *(u32*)(p + 0x15E0) = zero;
    *(u32*)(p + 0x15E4) = zero;
    *(u32*)(p + 0x15E8) = zero;
    *(u32*)(p + 0x15EC) = zero;
    *(u32*)(p + 0x15F0) = zero;
    *(u32*)(p + 0x15F4) = zero;
    *(u32*)(p + 0x15F8) = zero;
    *(u32*)(p + 0x15FC) = zero;
    *(u32*)(p + 0x1600) = zero;
    *(u32*)(p + 0x1604) = zero;
    *(u32*)(p + 0x1608) = zero;
    *(u32*)(p + 0x160C) = zero;
    *(u32*)(p + 0x1610) = zero;
    *(u32*)(p + 0x1614) = zero;
    *(u32*)(p + 0x1618) = zero;
    *(u32*)(p + 0x161C) = zero;
    *(u32*)(p + 0x1620) = zero;
    *(u32*)(p + 0x1624) = zero;
    *(u32*)(p + 0x1628) = zero;
    *(u32*)(p + 0x162C) = zero;
    *(u32*)(p + 0x1630) = zero;

    fn_80078768(lbl_805A01D8);

    q = *(char**)((char*)self + 0x1C);
    q[0x2] = 0;
    q[0x3] = 2;
    q[0x4] = 3;
    q[0x5] = 0;
    q[0x6] = 0xA;
    q[0x7] = 0;
    q[0x8] = 0;
    q[0x9] = 0;
    q[0xA] = 1;
    q[0xB] = 0;
    q[0xC] = 1;
    memset(q + 0x30, 0, 0x58);

    q = *(char**)((char*)g_GameGlobal + 0x34);
    memset(q, 0, 0x88);

    q[0x2] = 0x18;
    q[0x83] = 0;
    q[0x41] = 1;
    q[0x42] = 0x64;
    q[0x43] = 0x14;
    q[0x44] = 0xA;
    q[0x45] = 0x28;
    q[0x46] = 0x32;
    q[0x47] = 0x3C;
    q[0x4B] = 0xF;
    q[0x4E] = 0x19;
    q[0x50] = -100;
    q[0x51] = -100;
    q[0x52] = -100;
    q[0x53] = -100;
    q[0x54] = -100;
    q[0x57] = 0xA;
    q[0x58] = 0xF;
    q[0x59] = 0x14;
    q[0x5A] = 0x19;
    q[0x5B] = 0x46;
    q[0x5C] = 0x41;
    q[0x5D] = 0x3C;
    q[0x5E] = 0x32;
    q[0x60] = 1;
    q[0x61] = 1;
    q[0x62] = 2;
    q[0x63] = 3;
    q[0x64] = 3;
    q[0x65] = 2;
    q[0x66] = 1;
    q[0x68] = 2;
    q[0x69] = 5;
    q[0x6A] = 5;
    q[0x6B] = 4;
    q[0x6C] = 4;
    q[0x6D] = 3;
    q[0x6E] = 3;
    q[0x70] = 0xF;
    q[0x71] = 0xF;
    q[0x72] = 0xA;
    q[0x73] = 0xA;
    q[0x74] = 0xA;
    q[0x75] = 0xA;
    q[0x76] = 0x50;
}

}
