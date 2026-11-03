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
    char pad[0x5c];
    Src* src;
};

extern "C" void fn_80134250(Obj* self, Data* out) {
    *out = self->src->data;
}
