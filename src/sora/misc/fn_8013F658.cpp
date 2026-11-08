#include <types.h>
#include <string.h>
#include <gf/gf_callback.h>
#include <ip/ip_switch.h>
#pragma force_active on
struct Sub { u8 unk0; u8 unk1; u32 unk4; u8 unk8; u8 unk9; u16 unkA; u32 unkC; u32 unk10; u32 unk14; };
struct Elem { u32 unk0; Elem* next; u32 unk8; u8 unkC; u8 unkD; u16 unkE; u32 unk10; Sub subs[4]; char* unk74; };
struct Mgr {
 char pad0[0x14]; u8 unk14; char pad15[0x20-0x15]; Elem* elems;
 char pad24[0x48-0x24]; char* buf48; char pad4C[0xA8-0x4C]; u32 unkA8;
 char padAC[0x154-0xAC]; u32 unk154; char pad158[0x160-0x158]; void* unk160; s32 unk164;
 char pad168[0x450-0x168]; u32 unk450; u32 unk454; Elem* unk458;
};
extern Mgr* lbl_805A0390;
extern "C" int g_muWifiInterfaceTask;
extern "C" void fn_800D1A9C(int);
extern "C" void fn_8004A914(void*, int);
extern "C" void* lbl_805A0428;
static inline void resetMgr(Mgr* g) {
 int i;
 Elem* e = g->elems;
 for (i = 0; i < 20; i++) {
  char* p = g->buf48 + g->unk164 * i;
  e->unk0 = 0; e->next = 0; e->unk8 = 0; e->unkC = 0; e->unkD = 0; e->unkE = 0;
  for (u8 j = 0; j < 4; j++) {
   e->subs[j].unk0 = 0; e->subs[j].unk1 = 0; e->subs[j].unk8 = 0; e->subs[j].unk9 = 0;
   e->subs[j].unk4 = 0; e->subs[j].unkA = 0; e->subs[j].unkC = 0; e->subs[j].unk10 = 0;
  }
  e->unk74 = p; e++;
 }
 g->unk450 = 0; g->unk454 = 0; g->unk14 = 0; g->unk458 = g->elems;
 { Elem* p = g->unk458;
 for (int j = 0; j < 20; j++, p++) {
  if (j == 19) p->next = 0; else p->next = p + 1;
  p->unk8 = 0;
 } }
 memset(g->unk160, 0, g->unk154);
}
extern "C" void fn_8013F658() {
 fn_800D1A9C(g_muWifiInterfaceTask);
 lbl_805A0390->unkA8 = 0;
 resetMgr(lbl_805A0390);
 ipSwitch* sw = ipSwitch::getInstance();
 if (*(int*)sw == 1) {
  fn_8004A914(sw, 0);
  if (lbl_805A0428 != 0) {
   ((u8*)lbl_805A0428)[8] = 0;
   gfCallBack* cb = (gfCallBack*)lbl_805A0428;
   cb->userProc(); cb = cb->m_next;
   while (cb != 0) { cb->userProc(); cb = cb->m_next; }
  }
 }
}