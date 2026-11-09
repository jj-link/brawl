#include <types.h>
#pragma force_active on
struct Info { u8 pad[8]; u8 priority; };
struct Target {
    u8 bit : 1; u8 rest : 7; u8 pad[3];
    Info* info; s32 value; u8 b; u8 c; u8 pad2[2]; float x, y;
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Target* slot1(s32);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
};
class Class_7948 {
public:
    virtual void fn_27_689B0();
    virtual void fn_27_68A80();
    virtual void fn_27_68A90();
    virtual void fn_27_68BC0();
    virtual void fn_27_68C0C();
    virtual void fn_27_68CB0();
    virtual void fn_27_68D04();
    virtual u32 fn_27_68BA8();
    u8 pad[0x10]; Object_vptr_0* source; s32 id;
};
struct Vec { float x, y; };
extern "C" void fn_27_68A90(Class_7948* self, s32 id, s32 value, u8 c, Vec* vec) {
    if (self->fn_27_68BA8() == 1) {
        u8 priority = self->source->slot1(id)->info->priority;
        if (self->source->slot1(self->id)->info->priority > priority) return;
        Target* old = self->source->slot1(self->id);
        old->value = 0;
        old->b = 0;
        old->bit = 0;
    }
    Target* t = self->source->slot1(id);
    t->value = value;
    float y;
    float x = vec->x;
    t->b = 0;
    y = vec->y;
    t->c = c;
    t->x = x;
    t->y = y;
    t->bit = 1;
    self->id = id;
}