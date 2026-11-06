#include <types.h>
#include <revolution/OS/OSTime.h>
#include <mu/mu_object.h>
#pragma force_active on
extern "C" { void setFrameNode__8MuObjectFf(void*, float); void setFrameMatCol__8MuObjectFf(void*, float); extern float lbl_805A25C0; extern float lbl_805A25D4; }
class PClass { public: virtual void m01(); virtual void m02(); virtual void m03(); virtual void m04(); virtual void m05(); virtual void m06(); virtual void m07(); virtual void m08(); virtual void m09(); virtual void m10(); virtual void m11(); virtual void m12(u32,u32); virtual void m13(); virtual void m14(u32); unsigned char pad[0xE0]; u32 unk_e4; };
struct Listener { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void setFrame(float); };
struct Resource { unsigned char pad[0x0C]; Listener* listener; void* l1; void* l1b; Listener* l2; };
struct Item { unsigned char pad[0x10]; u32 unk10; Resource* resource; };
struct Self { unsigned char pad[0x40]; PClass* p; Item* items[6]; void* extra; unsigned char pad2[0x68]; unsigned long long time; };
extern "C" void fn_800F28F0(Self* self) {
    Item* first;
    int i = 0;
    unsigned char* cursor = (unsigned char*)self;
    while (i < 6) {
        Item* item = *(Item**)(cursor + 0x44);
        if (item) self->p->m14(item->unk10);
        ++i;
        cursor += 4;
    }
    if (self->extra) self->p->m14((u32)self->extra);
    first = self->items[0];
    self->p->m12(self->p->unk_e4, first->unk10);
    setFrameNode__8MuObjectFf(first, lbl_805A25C0);
    setFrameMatCol__8MuObjectFf(first, lbl_805A25C0);
    first->resource->listener->setFrame(lbl_805A25D4);
    first->resource->l2->setFrame(lbl_805A25D4);
    self->time = OSGetTime();
}