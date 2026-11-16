#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on
#pragma fp_contract on
#pragma opt_dead_assignments off
#pragma opt_unroll_loops off
extern "C" int __cntlzw(unsigned int);

struct Vec { float v[4]; Vec(); } __attribute__((aligned(16)));
inline Vec::Vec() {}
struct Matrix { float m[4][4]; } __attribute__((aligned(16)));
struct State {
 int countA, countB, limitA, limitB;
 char flag; char pad[3]; int changed; char pad1[8];
 Vec a[4], unused[4], b[4], localB[4];
 Vec dir; float pad3[16]; int status;
 State() : flag(0) {}
};
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10();
 virtual void slot11(void*, int, Vec*);
 char pad[8]; float radius;
};
struct Node { Object_vptr_0* shape; void* key; Matrix* transform; };
class Handler {
public:
 virtual void slot0(); virtual void slot1(Node*, Node*);
};
struct Self { char pad[12]; short indices[4]; signed char countA, countB, limitA, limitB; char pad18[8]; float x,y,z,w; };
struct TimerEntry { char* name; u32 time, unused; };
struct Timer { u32 unused0; TimerEntry* current; u32 unused8; TimerEntry* end; u32 unused10[2]; };
struct Rec16 { char* name; u32 time, unused; char* name2; };
extern Timer lbl_80532448;
extern char lbl_8040FCA8[];
extern const float lbl_805A3F38;
extern "C" void fn_80287600(Matrix*, const Matrix*, const Matrix*);
extern "C" int fn_803198C8(State*, Object_vptr_0*, Object_vptr_0*, Matrix*, Vec*);
extern "C" void fn_8031AB44(State*, void*);
#define RECORD(offset) { \
 Timer* timer = &lbl_80532448; \
 signed char c = (signed char)(((u32)timer->end << __cntlzw((u32)timer->end ^ (u32)timer->current)) >> 31); \
 if (((u32)(-c | c) >> 31) != 0) { \
  TimerEntry* entry = timer->current; entry->name = lbl_8040FCA8 + (offset); \
  register u32 t; asm { mftb t } \
  entry->time = t; timer->current = entry + 1; \
 } \
}
#define START() { \
 Timer* timer = &lbl_80532448; \
 signed char c = (signed char)(((u32)timer->end << __cntlzw((u32)timer->end ^ (u32)timer->current)) >> 31); \
 if (((u32)(-c | c) >> 31) != 0) { \
  Rec16* entry = (Rec16*)timer->current; entry->name = lbl_8040FCA8 + 9; entry->name2 = lbl_8040FCA8 + 15; \
  register u32 t; asm { mftb t } \
  entry->time = t; timer->current = (TimerEntry*)(entry + 1); \
 } \
}
extern "C" void fn_802B2140(Self* self, Node* a, Node* b, void* unused, Handler* handler) {
 START()
 RECORD(21)
 Object_vptr_0* sa = a->shape;
 Object_vptr_0* sb = b->shape;
 Matrix matrix;
 Matrix* mb = b->transform;
 Matrix* ma = a->transform;
 fn_80287600(&matrix, ma, mb);
 State state;
 state.flag = 1;
 state.countA = self->countA;
 state.countB = self->countB;
 state.limitA = self->limitA;
 state.limitB = self->limitB;
 state.changed = 0;
 sa->slot11(self->indices, state.countA, state.a);
 sb->slot11(self->indices + state.countA, state.countB, state.localB);
 Vec out;
 int result = fn_803198C8(&state, sa, sb, &matrix, &out);
 if (state.changed) fn_8031AB44(&state, self->indices);
 if (result == 0) {
  Matrix* m = a->transform;
  float ra = sa->radius;
  float x = out.v[0], y = out.v[1], z = out.v[2];
  float rb = sb->radius;
  float d = (out.v[3] - ra) - rb;
  self->x = z * m->m[2][0] + (x * m->m[0][0] + y * m->m[1][0]);
  self->y = z * m->m[2][1] + (x * m->m[0][1] + y * m->m[1][1]);
  self->z = z * m->m[2][2] + (x * m->m[0][2] + y * m->m[1][2]);
  self->w = d;
  if (d < lbl_805A3F38) handler->slot1(a,b);
 } else {
  self->w = lbl_805A3F38;
  self->z = lbl_805A3F38;
  self->y = lbl_805A3F38;
  self->x = lbl_805A3F38;
  handler->slot1(a,b);
 }
 RECORD(33)
}