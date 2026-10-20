#pragma force_active on
struct Entry {
    unsigned char data[0x18];
};

struct Group {
    Entry* entries;
    unsigned char padding[12];
};

struct State {
    unsigned char pad0[0x54];
    Group groups[1];
    unsigned char pad64[4];
    void* target;
    unsigned char pad6C[0x31C];
    int group;
    int index;
    int state;
};

extern "C" void fn_800397B0(void*, int, Entry*);
extern "C" void fn_80039654(void*, int, Entry*);

extern "C" void fn_11_8408(State* self) {
    Entry* entry = &self->groups[self->group].entries[self->index];

    if (self->group == 1)
        fn_800397B0(self->target, 3, entry);
    else
        fn_80039654(self->target, 3, entry);

    self->state = 2;
}
