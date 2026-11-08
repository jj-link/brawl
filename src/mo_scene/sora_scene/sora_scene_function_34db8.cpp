#pragma force_active on
#include <types.h>
struct Mode {
 char pad[8];
 u8 f8:6; u8 f8b:2;
 u8 f9:3; u8 f9b:5;
 u8 fa0:1; u8 fa1:1; u8 fa2:1; u8 fa3:1; u8 fa4:4;
 u8 fb0:5; u8 fb1:1; u8 fb2:2;
 u8 fc:1; u8 fc1:7;
 char pad0[6]; u8 f13; char pad1[2]; u8 f16; u8 pad17; u8 f18; u8 pad19; u16 f1a;
 char f1c[4]; int f20; char pad24[12]; int f30; int f34; int f38; int f3c; char pad40[28]; char f5c[4]; char pad60[3]; u8 f63; u8 f64; char pad65[3]; int f68; int f6c; int f70; int f74; int f78; int f7c;
};
extern "C" {
void fn_8005033C(void*);
void fn_1_350F8(void*);
void fn_1_34FA0(void*);
void fn_1_3D378();
void fn_8010F960(u16, void*, void*, int);
extern void* g_GameGlobal;
void fn_1_34DB8(void* arg) {
 Mode* a = *(Mode**)((u8*)g_GameGlobal + 8);
 u8* self = (u8*)arg;
 u8* b = *(u8**)((u8*)g_GameGlobal + 16);
 fn_8005033C(a);
 int count = 0;
 *(u32*)(self + 0x18) = count;
 *(u32*)(self + 0x1C) = count;
 *(u32*)(self + 0x20) = count;
 u8* p = b;
 for (int i = 0; i < 4; i++, p += 0x5c) {
  if (p[0xb9] != 3) ++*(u32*)(self + 0x1c);
 }
 int one = (*(u32*)(self + 0x1C) == 1);
 self[0x13] = one;
 int flag = !one && b[1] == 0;
 self[0x14] = flag;
 if (flag) fn_1_350F8(self); else fn_1_34FA0(self);
 a->f8 = 9; a->f1a = 0x34; a->f13 = self[0x14] != 0;
 a->f9 = 1; a->f20 = 600; a->fc = 0; a->fb1 = 0;
 a->f18 = 0; a->f63 = self[0x13]; a->f64 = self[0x14];
 a->f68 = *(u32*)(self + 0x18); a->f6c = *(u32*)(self + 0x20);
 a->fa3 = 1; a->f70 = 0; a->f74 = 0; a->f78 = 0; a->f7c = 0;
 a->f34 = 0; a->f30 = 0; a->f38 = 0; a->f3c = 0; a->f16 = 0;
 if (self[0x12]) { self[0x12] = 0; fn_1_3D378(); }
 fn_8010F960(a->f1a, a->f1c, a->f5c, 0);
}
}