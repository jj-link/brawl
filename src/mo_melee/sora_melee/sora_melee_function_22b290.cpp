#include <types.h>
#pragma force_active on

struct Entry {
    u8 pad[4];
    u16 id;
    f32 f0, f1, f2, f3, f4;
    u32 a, b;
};
struct Out {
    u16 id;
    f32 f0, f1, f2, f3, f4;
    u32 a, b;
};
struct Owner {
    u8 pad[0x40];
    Entry* table40;
    Entry* table44;
};
extern "C" s32 fn_27_22AD58(Owner*, Entry*, u32, u32*);
extern "C" s32 fn_27_22B290(Owner* self, u32 key, Out* out) {
    u32 idx;
    if (fn_27_22AD58(self, self->table40, key, &idx) != 0) {
        Entry* e = &self->table40[idx];
        out->id = e->id;
        out->f0 = e->f0;
        out->f1 = e->f1;
        out->f2 = e->f2;
        out->f3 = e->f3;
        out->f4 = e->f4;
        out->a = e->a;
        out->b = e->b;
        return 1;
    }
    if (fn_27_22AD58(self, self->table44, key, &idx) != 0) {
        Entry* e = &self->table44[idx];
        out->id = e->id;
        out->f0 = e->f0;
        out->f1 = e->f1;
        out->f2 = e->f2;
        out->f3 = e->f3;
        out->f4 = e->f4;
        out->a = e->a;
        out->b = e->b;
        return 1;
    }
    return 0;
}