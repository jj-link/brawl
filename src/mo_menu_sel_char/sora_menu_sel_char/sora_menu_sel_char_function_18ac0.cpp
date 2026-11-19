#include <gm/gm_global.h>
#include <gf/gf_pad_status.h>
#pragma force_active on
extern "C" {
struct TargetData { char pad[0x5c8]; unsigned char f5c8; };
struct SelCharSelf { char pad[0x1b0]; int f1b0; int f1b4; char p1b8[8]; int f1c0; char p1c4[4]; int f1c8; char p1cc[12]; int f1d8; char p1dc[0x18]; TargetData* f1f4; char p1f8[4]; char list[0x160]; };
void fn_10_18908(void*, int, int, int, int);
void fn_8004D674(void*, int, short*);
void fn_800D3184(void*, int, short*, int);
void fn_10_14F38(void*, int, int);
int fn_10_1D5C4(void*, gfPadStatus*, int*);
void fn_10_1DE50(void*);
extern void* g_muWifiInterfaceTask;
}
static inline void copyPad(gfPadStatus& d, const gfPadStatus& s) {
 d.m_buttonsCurrentFrame = s.m_buttonsCurrentFrame;
 d.m_buttonsCurrentFrame2 = s.m_buttonsCurrentFrame2;
 d.m_buttonsHeld = s.m_buttonsHeld;
 d.m_buttonsPressedThisFrame = s.m_buttonsPressedThisFrame;
 d.m_buttonsReleasedThisFrame = s.m_buttonsReleasedThisFrame;
 d.m_buttonsPressedThisFrame2 = s.m_buttonsPressedThisFrame2;
 d._0x18 = s._0x18; d._0x1c = s._0x1c; d._0x20 = s._0x20;
 d._0x24 = s._0x24; d._0x28 = s._0x28; d._0x2c = s._0x2c;
 d.m_stickX = s.m_stickX; d.m_stickY = s.m_stickY;
 d.m_subStickX = s.m_subStickX; d.m_subStickY = s.m_subStickY;
 d.m_lTriggerAnalog = s.m_lTriggerAnalog; d.m_rTriggerAnalog = s.m_rTriggerAnalog;
 d._0x36 = s._0x36; d._0x37 = s._0x37; d.m_error = s.m_error;
 d.m_controllerType = s.m_controllerType;
}
extern "C" int fn_10_18AC0(void* arg0, const gfPadStatus* arg1, const gfPadStatus* arg2) {
 SelCharSelf* self = (SelCharSelf*)arg0;
 gfPadStatus status;
 copyPad(status, *arg1);
 status.m_buttonsCurrentFrame2 = arg2->m_buttonsHeld;
 status.m_buttonsPressedThisFrame = arg2->m_buttonsPressedThisFrame;
 status.m_buttonsPressedThisFrame2 = arg2->m_buttonsReleasedThisFrame;
 int name;
 int result;
 int index;
 switch (fn_10_1D5C4(&self->list, &status, &name)) {
 case 2:
 {
  if (name != self->f1c8) {
   index = name;
   fn_10_18908(self, index, self->f1b4, self->f1f4[0].f5c8, self->f1c0);
   self->f1c8 = index;
   void* task = g_muWifiInterfaceTask;
   if (task != 0) {
    short text[6];
    int r;
    int kind = 0;
    if (index < 0) goto clear;
    {
     int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
     if (state >= 0 && state < 4) kind = 1; else kind = 0;
     if (kind != 0) kind = 0;
     else {
      if (state >= 4 && state < 0xc) kind = 1; else kind = 0;
      if (kind != 0) kind = 1;
      else {
       if (state >= 0xc && state < 0x10) r = 1; else r = 0;
       kind = 3;
       if (r != 0) kind = 2;
      }
     }
    }
    if (kind == 2) fn_8004D674(g_GameGlobal, index, text);
    else goto clear;
    goto done;
clear:
    text[0] = 0;
done:
    int slot = self->f1b0;
    fn_800D3184(task, slot, text, index >= 0 ? index & 0xff : 0x78);
   }
   self->f1d8 = 0;
   fn_10_14F38(arg0, 0, self->f1b4);
  }
  result = 1;
  break;
 }
 case 3: result = 1; break;
 case 4: result = 2; break;
 case 5:
  name = -1;
  if (self->f1c8 != -1) {
   fn_10_18908(arg0, -1, self->f1b4, self->f1f4->f5c8, self->f1c0);
   self->f1c8 = -1;
   void* task = g_muWifiInterfaceTask;
   if (task != 0) {
    short text[6];
    text[0] = 0;
    fn_800D3184(task, self->f1b0, text, 0x78);
   }
   self->f1d8 = 0;
   fn_10_14F38(arg0, 0, self->f1b4);
  }
  result = 1; break;
 case 1: result = 0; break;
 }
 if (result != 0) fn_10_1DE50(&self->list);
 return result;
}