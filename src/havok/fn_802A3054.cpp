#include <types.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);
struct Rec { const char* name; u32 time; u32 pad; };
struct TraceBuf { u32 unk0; Rec* cur; u32 unk8; Rec* end; };
extern TraceBuf lbl_80532448;
extern char lbl_8040FB60[];
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(); virtual void slot2(void*, int, int, int); };
struct VTbl { char pad[12]; void* fn; };
struct Arg1 { VTbl* vt; u32 unk4; u32 unk8; };
struct Msg { void* a; u32 b; u32 c; Arg1* d; };
struct Holder { char pad[12]; Object_vptr_0* child; };
template <int offset> inline void trace() {
 TraceBuf* buf = &lbl_80532448;
 Rec* cur = buf->cur;
 Rec* end = buf->end;
 if ((s8)(((u32)end << __cntlzw((u32)end ^ (u32)cur)) >> 31)) {
  cur->name = lbl_8040FB60 + offset;
  register u32 t;
  asm { mftb t }
  cur->time = t;
  buf->cur = cur + 1;
 }
}
extern "C" void fn_802A3054(Holder* arg0, Arg1* arg1, int x, int y, int z) {
 u32 c;
 u32 b;
 VTbl* a;
 trace<0x26>();
 Msg msg;
 c = arg1->unk8;
 msg.d = arg1;
 a = arg1->vt;
 msg.c = c;
 b = arg1->unk4;
 void* shape = a->fn;
 msg.b = b;
 msg.a = shape;
 arg0->child->slot2(&msg, x, y, z);
 trace<0x32>();
}
