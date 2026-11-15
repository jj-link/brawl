#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on
extern "C" int __cntlzw(unsigned int);
struct Body;
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3(Body*, void*, void*, void*);
};
class Class_80487228 {
public:
 virtual void fn_802C8FC4();
 virtual void fn_80080A64();
 virtual void fn_802C9FAC();
 virtual void fn_802C9D24();
};
struct Shape { char pad[0x10]; void* child; char pad2[0x1c]; char transform[1]; };
struct Body {
 const Shape* shape; unsigned int key; void* data; const Body* parent;
};
struct Self { char pad[0xc]; Object_vptr_0* child; };
struct TimerEntry { char* name; unsigned int time; unsigned int unused; };
struct Timer { unsigned int unused0; TimerEntry* current; unsigned int unused8; TimerEntry* end; unsigned int unused10[2]; };
extern Timer lbl_80532448;
extern char lbl_8040FFA0[];
extern "C" void fn_802873E8(void*, void*, void*);
inline void record(int offset) {
 Timer* timer = &lbl_80532448;
 TimerEntry* entry = timer->current;
 if ((signed char)(((unsigned int)timer->end << __cntlzw((unsigned int)timer->end ^ (unsigned int)entry)) >> 31)) {
  entry->name = lbl_8040FFA0 + offset;
  register u32 t;
  asm { mftb t }
  entry->time = t;
  timer->current = entry + 1;
 }
}
extern "C" void fn_802C9D24(Self* self, const Body* arg1, void* a2, void* a3, void* a4) {
 record(0);
 const Shape* shape = arg1->shape;
 Body body;
 __attribute__((aligned(16))) unsigned char transform[0x40];
 fn_802873E8(transform, arg1->data, (void*)shape->transform);
 body.parent = arg1;
 body.data = transform;
 const Shape* child = (const Shape*)shape->child;
 body.key = arg1->key;
 body.shape = child;
 self->child->slot3(&body, a2, a3, a4);
 record(12);
}
