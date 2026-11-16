#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on
extern "C" {
u8 fn_800C851C();
u8 fn_800C8548();
void netReport__FPCce(const char*, ...);
extern char lbl_80457158[];
extern u8 lbl_805A0414;
}
inline void countPlayers(s32& count, u8& i, u8* p) {
    if (p == 0) count = -1;
    else {
        count = 0;
        for (i = 0; i < 4; i++) {
            u8* q = p + i * 0x18;
            for (int j = 0; j < 3; j++) {
                if ((*(s32*)(q + 0x84 + j * 8) >> 24) != 0) count++;
            }
        }
    }
}
extern "C" s32 fn_800D64A8(u8* self, s32 slot) {
u8* gg;
u8 idx;
u8 l;
u32 ctr;
u8 kk;
u8 kkb;
u8* e;
u8* sub;
u8* p;
s32 r6;
s32 r6b;
s32 cnt;
s32 r;
s32 b0;
s32 b8;
s32 r3;
const char* base;
base = lbl_80457158;
gg = (u8*)g_GameGlobal->m_selCharData;
if (gg[6] != 0) return 0;
idx = fn_800C851C();
if (idx == 0xFF) idx = 4;
e = self + idx * 0x218;
if (!((e[0xE8] >> 7) & 1) || (s32)lbl_805A0414 > 1) {
    l = fn_800C851C();
    if (l == 0xFF) l = 4;
    if (l != 4) goto D;
}
if (slot == 0 && slot >= 4) return 0;
if ((*(s32*)(self + slot * 8 + 0x50) >> 24) == 1) return 0;
idx = fn_800C8548();
p = (idx == 0xFF) ? 0 : (u8*)((s32)self + idx * 0x218 + 0x70);
countPlayers(r6, kk, p);
if (r6 >= 4) return 0;
b0 = *(s32*)(e + 0xB0) >> 24;
r3 = 0;
if (b0 == 0) r3 = 1;
else {
    b8 = *(s32*)(e + 0xB8) >> 24;
    if (b8 == 0) r3 = 2;
}
return r3 != 0;
D:
l = fn_800C851C();
if (l == 0xFF) l = 4;
if (l == 4) return 0;
if (slot != 0) {
    idx = fn_800C8548();
    sub = (idx == 0xFF) ? 0 : self + idx * 0x218 + 0x70;
    if (sub == 0) cnt = 1;
    else {
        cnt = 0;
        if ((s32)sub[0x68] == 1) cnt = 1;
        if ((s32)sub[0x69] == 1) cnt++;
        if ((s32)sub[0x6A] == 1) cnt++;
        if ((s32)sub[0x6B] == 1) cnt++;
    }
    if (cnt < 2) return 0;
}
idx = fn_800C8548();
sub = (idx == 0xFF) ? 0 : (u8*)((s32)self + idx * 0x218 + 0x70);
if (sub == 0) return 0;
if (sub[0x6C] != 0xFF) return 0;
if ((self + slot * 8)[0x4C] != 0xFF) return 0;
r = *(s32*)(self + slot * 8 + 0x50) >> 24;
if (r == 1) {
    netReport__FPCce(base + 0x20B8, sub[0x6C], sub[0x6D]);
    return 0;
}
if (r == 3) {
    netReport__FPCce(base + 0x2100, sub[0x6C], sub);
    return 0;
}
idx = fn_800C8548();
p = (idx == 0xFF) ? 0 : (u8*)((s32)self + idx * 0x218 + 0x70);
countPlayers(r6b, kkb, p);
if (r6b >= 4) return 0;
b0 = *(s32*)(e + 0xB0) >> 24;
if (b0 > 1 || (b8 = *(s32*)(e + 0xB8) >> 24) > 1) {
    netReport__FPCce(base + 0x2120);
    return 0;
}
r3 = 0;
if (b0 == 0) r3 = 1;
else if (b8 == 0) r3 = 2;
return r3 != 0;
}