#include <types.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);
struct Context;
struct ByteResult { signed char value; };
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual ByteResult slot5(void*, Context*);
};
class Class_804873C8 {
public:
 virtual void fn_802CE6B4();
 virtual void fn_802CEA00();
 virtual void fn_802CE81C();
 virtual void fn_802CE808();
 virtual void fn_802D4AB4();
 virtual void fn_802CE824();
};
struct Context { char pad[0x18]; void* entries[8]; int depth; };
struct Self { char pad[0x14]; Object_vptr_0* object; };
struct TimerEntry { char* name; unsigned int time; unsigned int unused; };
struct Timer { unsigned int unused0; TimerEntry* current; unsigned int unused8; TimerEntry* end; unsigned int unused10[2]; };
extern Timer lbl_80532448;
extern char lbl_804103D0[];
inline void record(int offset) {
 Timer* timer = &lbl_80532448;
 TimerEntry* entry = timer->current;
 if ((signed char)(((unsigned int)timer->end << __cntlzw((unsigned int)timer->end ^ (unsigned int)entry)) >> 31)) {
  entry->name = lbl_804103D0 + offset;
  register u32 t;
  asm { mftb t }
  entry->time = t;
  timer->current = entry + 1;
 }
}
extern "C" ByteResult fn_802CE824(Self* self, void* arg, Context* ctx) {
 record(0);
 ctx->depth++;
 ByteResult result = self->object->slot5(arg, ctx);
 int d = --ctx->depth;
 if (result.value) ctx->entries[d] = 0;
 record(12);
 return result;
}