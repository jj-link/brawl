#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on
extern "C" u16* fn_8004DA14(void*, int, int);
extern float lbl_805A1890;
struct Bits { u8 upper : 4; u8 bit3 : 1; u8 bit2 : 1; u8 bit1 : 1; u8 bit0 : 1; };
struct HighFlag { u8 high : 1; u8 rest : 7; };
struct Flags { u8 mode : 3; u8 rest : 5; };
inline void setMode(u8* self, u8* rec) {
 ((Flags*)(self + 9))->mode = rec[2];
 switch ((self[9] >> 5) & 7) {
 case 0:
 default: self[9] |= 2; *(s32*)(self + 0x20) = rec[3] * 3600; break;
 case 1: self[9] |= 2; *(s32*)(self + 0x20) = rec[8] * 3600; break;
 case 2: self[9] |= 2; *(s32*)(self + 0x20) = rec[3] * 3600; break;
 }
}
extern "C" void fn_80050424(u8* self) {
 g_GameGlobal->getGlobalRecordMenuDatap();
 u8* rec = (u8*)g_GameGlobal->m_setRule;
 u8* sp = (u8*)g_GameGlobal->m_selCharData;
 setMode(self, rec);
 s32 t = *(s32*)(self + 0x20);
 ((HighFlag*)(self + 0xA))->high = t != 0;
 u8* cur = self;
 for (int i = 0; i < 4; i++) {
  switch (rec[5]) {
  case 0:
  default: *(u16*)(cur + 0xBE) = 0; break;
  case 1: { u16* p = fn_8004DA14(g_GameGlobal, i, sp[0xD0]); *(u16*)(cur + 0xBE) = p ? *p : 0; break; }
  case 2: *(u16*)(cur + 0xBE) = *(u16*)(sp + 0xDE); break;
  }
  *(u16*)(cur + 0xBA) = *(u16*)(cur + 0xBE);
  cur += 0x5C; sp += 0x5C;
 }
 float f = (float)rec[6] / lbl_805A1890;
 *(float*)(self + 0x4C) = f;
 *(float*)(self + 0xD0) = f;
 *(float*)(self + 0x12C) = f;
 *(float*)(self + 0x188) = f;
 *(float*)(self + 0x1E4) = f;
 ((Bits*)(self + 0xA))->bit0 = rec[9];
 ((Bits*)(self + 0xB))->bit3 = rec[10];
 switch ((self[9] >> 5) & 7) {
 case 0:
 default:
  ((HighFlag*)(self + 0xC))->high = rec[11];
  self[0xB] |= 4;
  break;
 case 1: self[0xC] |= 0x80; self[0xB] &= ~4; break;
 case 2: self[0xC] |= 0x80; self[0xB] |= 4; break;
 }
 ((Bits*)(self + 0xB))->bit1 = rec[12] == 0;
}