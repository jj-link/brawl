#include <types.h>
#include <sr/sr_common.h>
#pragma force_active on
extern "C" void fn_27_5AD88(void*, void*, int, int);
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" char lbl_27_data_6248[];
class Getter {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual s16 get();
};
class Class_C80 {
public:
 virtual void fn_27_FEE4();
 virtual void fn_27_FF68();
 virtual Heaps::HeapType fn_27_FFAC();
};
class Obs {
public:
 virtual void addObserver(s32, s32);
 s16 id, kind, link;
};
struct Data { int unk; int count; };
struct Entry { signed char a, b, c; };
struct Self {
 void* vt; void* vt4; char pad[12]; Obs obs;
 Data* data; Entry* entries; int value; bool active;
};
extern "C" Self* fn_27_5B248(Self* self, void* owner, Data* data, int value) {
 fn_27_5AD88(self, owner, 0, -1);
 char* module = *(char**)((char*)owner + 0xd8);
 char* object = *(char**)(module + 0x80);
 s16 id = ((Getter*)(object + 8))->get();
 self->obs.id = -1;
 self->obs.kind = 4;
 self->obs.link = -1;
 *(void***)&self->obs = __vt__21soStatusEventObserver;
 self->obs.addObserver((s32)id, -1);
 self->vt = lbl_27_data_6248;
 self->vt4 = lbl_27_data_6248 + 0x34;
 *(void**)&self->obs = lbl_27_data_6248 + 0x50;
 self->data = data;
 self->entries = 0;
 self->value = value;
 self->active = true;
 module = *(char**)((char*)owner + 0xd8);
 Heaps::HeapType heap = (*(Class_C80**)(module + 0xc0))->fn_27_FFAC();
 self->entries = (Entry*)operator new[](self->data->count * 3, heap);
 for (int i = 0; i < self->data->count; i++) {
  self->entries[i].b = -2;
  self->entries[i].a = -1;
  self->entries[i].c = 0;
 }
 return self;
}