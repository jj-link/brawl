#pragma force_active on

typedef unsigned int u32;

struct Data {
    u32 v[14];
};

struct Src {
    u32 head;
    Data data;
};

struct Obj {
    char pad[0x60];
    Src* src;
};

extern "C" void fn_801341D8(Obj* self, Data* out) {
    *out = self->src->data;
}
