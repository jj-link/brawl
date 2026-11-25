#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on
extern "C" int __cntlzw(unsigned int);
struct Body;
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual int slot2();
};
struct Shape { char pad[0x10]; Object_vptr_0* child; char pad2[0x1c]; char transform[1]; };
struct Body {
 const Shape* shape; unsigned int key; void* data; const Body* parent;
};
struct Arg { Object_vptr_0* obj; };
struct Table { unsigned char pad[0x190]; unsigned char indices[0x800]; };
struct Other { Table* table; };
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
extern "C" void fn_802CA0D4(const Body* arg0, Arg* arg1, Other* arg2, void* arg3) {
 record(0);
 const Shape* shape = arg0->shape;
 Body body;
 __attribute__((aligned(16))) unsigned char transform[0x40];
 fn_802873E8(transform, arg0->data, (void*)shape->transform);
 body.parent = arg0;
 body.data = transform;
 Object_vptr_0* child = shape->child;
 body.key = arg0->key;
 body.shape = (const Shape*)child;
 int a = child->slot2();
 int b = arg1->obj->slot2();
 Table* table = arg2->table;
 typedef void (*Callback)(Body*, Arg*, Other*, void*);
 (*(Callback*)((char*)table + 0x994 + *((unsigned char*)table + 0x190 + a * 32 + b) * 20))(&body, arg1, arg2, arg3);
 record(12);
}
