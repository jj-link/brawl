#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
struct Value { u32 a,b,c; u8 d,e; };
struct SrcValue { Value v; u8 pad[8]; };
struct Target { u8 pad[0x75]; u8 flags; u8 pad2[0xd4-0x76]; Value values[8]; };
struct Source { u8 pad[0xd]; u8 enabled; u8 pad2[0x18-0xe]; Target *target; u8 pad3[0x3c-0x1c]; SrcValue values[7]; Value last; u8 type; };
extern "C" void fn_801340A0(void*);
extern "C" void fn_80124080(Source* p) {
 if (!p->enabled) return;
 if (p->type == 3) {
  Target *t = p->target;
  t->values[3] = p->values[3].v;
  t->flags |= 0x80;
  fn_801340A0(p->target);
 } else if (p->type == 0) {
  p->target->values[0] = p->values[0].v;
  p->target->flags |= 0x40;
 } else if (p->type == 2) {
  p->target->values[2] = p->values[2].v;
  p->target->flags |= 0x10;
 } else if (p->type == 1) {
  p->target->values[1] = p->values[1].v;
  p->target->flags |= 0x20;
 } else if (p->type == 4) {
  p->target->values[4] = p->values[4].v;
  p->target->flags |= 4;
 } else if (p->type == 5) {
  p->target->values[5] = p->values[5].v;
  p->target->flags |= 8;
 } else if (p->type == 6) {
  p->target->values[6] = p->values[6].v;
  p->target->flags |= 1;
 } else if (p->type == 7) {
  p->target->values[7] = p->last;
  p->target->flags |= 2;
 }
}