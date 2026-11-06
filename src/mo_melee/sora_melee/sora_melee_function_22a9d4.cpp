#include <sr/sr_common.h>
#pragma force_active on

struct Data36 { u32 value; char pad[0x20]; };
struct Data20 { u32 value; char pad[0x10]; };
struct Data16 { u32 value; char pad[0x0C]; };
struct Obj {
    char pad[0x40];
    Data36* a;
    Data36* b;
    Data20* c;
    Data16* d;
    u32 count;
};

extern "C" void fn_27_22A9D4(Obj* self, int count) {
    if (self->count != 0) {
        self->count = 0;
        if (self->a) delete[] self->a;
        if (self->b) delete[] self->b;
        if (self->c) delete[] self->c;
        if (self->d) delete[] self->d;
        self->a = 0;
        self->b = 0;
        self->c = 0;
        self->d = 0;
    }
    self->count = count;
    self->a = new (Heaps::StageInstance) Data36[count];
    self->b = new (Heaps::StageInstance) Data36[count];
    self->c = new (Heaps::StageInstance) Data20[count];
    self->d = new (Heaps::StageInstance) Data16[count];
    for (u32 i = 0; i < self->count; ++i) self->a[i].value = 0;
    for (u32 i = 0; i < self->count; ++i) self->b[i].value = 0;
    for (u32 i = 0; i < self->count; ++i) self->c[i].value = 0;
    for (u32 i = 0; i < self->count; ++i) self->d[i].value = 0;
}
