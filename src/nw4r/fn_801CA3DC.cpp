#pragma force_active on
typedef unsigned int u32;

struct Entry {
    u32 unk;
    u32 value;
};

struct Obj {
    unsigned char pad0[0x14];
    Entry* list;
};

extern "C" void fn_801CA3DC(Obj* self, u32 lo, u32 hi) {
    if (self->list != 0) {
        for (u32 i = 0; i < self->list[0].unk; ++i) {
            Entry* e = &self->list[i];
            if (lo <= e->value && e->value <= hi) {
                e->value = 0;
            }
        }
    }
}
