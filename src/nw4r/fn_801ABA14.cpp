#include <types.h>
#pragma force_active on
class NodeObj {
public:
 virtual void vf0();
 virtual void vf1(u32, void*, void*);
};
class HandlerObj {
public:
 virtual void vf0();
 virtual void vf1(u32, void*, void*, void*);
 virtual void vf2(u32, void*, void*, void*);
 virtual void vf3(u32, void*, void*, void*);
};
class SelfObj {
public:
 virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3();
 virtual void vf4(); virtual void vf5(); virtual void vf6(); virtual void vf7();
 virtual void vf8(); virtual void vf9(); virtual void vf10(void*, void*);
 virtual void vf11(); virtual void vf12(); virtual void vf13(void*);
 u32 field_04;
 u8 pad_08[0x34];
 void* field_3c;
 u8 pad_40[0x2c];
 void* field_6c;
 u8 pad_70[0x64];
 HandlerObj* handler;
 u8 flags8;
 u8 pad_d9;
 u16 flags16;
 NodeObj** nodes;
 u8 pad_e0[4];
 u32 node_count;
};
extern "C" void fn_801AB8C0(void*, void*, void*);
extern "C" void fn_801EC1B8(void*, void*, void*);
inline void callback(SelfObj* p, u32 timing, void* param, void* info) {
 HandlerObj* h = p->handler;
 if (h && (p->flags16 & 1) && (p->flags8 & timing))
  h->vf1(timing, p, param, info);
}
extern "C" void fn_801ABA14(void* self, int cmd, void* arg2, void* arg3) {
 SelfObj* p = (SelfObj*)self;
 switch (cmd) {
 case 5:
  fn_801AB8C0(self, arg2, arg3);
  break;
 case 1: {
  void* sp8 = arg2;
  HandlerObj* h = p->handler;
  if (h && (p->flags16 & 1) && (p->flags8 & 1))
   h->vf1(1, self, arg2, arg3);
  p->vf10(arg3, &sp8);
  callback(p, 2, sp8, arg3);
  void* matrix = &p->field_3c;
  u32 i = 0;
  u32 offset = 0;
  while (i < p->node_count) {
   (*(NodeObj**)((u8*)p->nodes + offset))->vf1(1, sp8, matrix);
   offset += 4;
   i++;
  }
  callback(p, 4, sp8, arg3);
  break;
 }
 case 2: {
  HandlerObj* h = p->handler;
  if (h && (p->flags16 & 2) && (p->flags8 & 1))
   h->vf2(1, self, arg2, arg3);
  u32 offset;
  u32 i;
  i = 0;
  offset = 0;
  while (i < p->node_count) {
   (*(NodeObj**)((u8*)p->nodes + offset))->vf1(2, arg2, arg3);
   offset += 4;
   i++;
  }
  h = p->handler;
  if (h && (p->flags16 & 2) && (p->flags8 & 4))
   h->vf2(4, self, arg2, arg3);
  break;
 }
 case 4: {
  HandlerObj* h = p->handler;
  if (h && (p->flags16 & 4) && (p->flags8 & 1))
   h->vf3(1, self, arg2, arg3);
  fn_801EC1B8(arg3, (void*)&p->field_3c, (void*)&p->field_6c);
  h = p->handler;
  if (h && (p->flags16 & 4) && (p->flags8 & 2))
   h->vf3(2, self, arg2, arg3);
  u32 offset;
  u32 i;
  i = 0;
  offset = 0;
  while (i < p->node_count) {
   (*(NodeObj**)((u8*)p->nodes + offset))->vf1(4, arg2, arg3);
   offset += 4;
   i++;
  }
  h = p->handler;
  if (h && (p->flags16 & 4) && (p->flags8 & 4)) {
   h->vf3(4, self, arg2, arg3);
   break;
  }
  break;
 }
 case 6:
 case 7:
  return;
 case 0x10001:
  p->vf13(arg3);
  break;
 case 0x10003:
  p->field_04 = 0;
  break;
 case 0x10002:
  p->field_04 = (u32)arg3;
  break;
 case 3:
 case 8:
 case 0x10004:
 default:
  for (u32 i = 0; i < p->node_count; i++)
   p->nodes[i]->vf1((u32)cmd, arg2, arg3);
  break;
 }
}
