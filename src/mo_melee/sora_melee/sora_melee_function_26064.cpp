#include <types.h>
#pragma force_active on

typedef struct {
    u16 pad[7];
    u16 flags;
    u8 a;
    u8 b;
} FooElem;

typedef struct {
    u32 a;
    u16 count;
    u16 b;
    u32 c;
    u32 d;
    u32 e;
    FooElem* arr;
} Foo;

typedef struct {
    u32 pad[12];
    Foo* foo;
} This;

extern "C" void fn_27_26064(This* self, u16 value, s32 id) {
    Foo* obj = self->foo;
    if (obj == 0) return;
    s32 count = obj->count;
    FooElem* p = obj->arr;
    if (count == 0 || p == 0) return;
    for (s32 i = 0; i < count; i++, p++) {
        if (id != -1 && (id & p->flags)) continue;
        p->flags = value | (p->flags & ~0xF);
    }
}
