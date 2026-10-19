#pragma force_active on
typedef unsigned int u32;

struct IkeTriple {
    u32 a;
    u32 b;
    u32 c;
};

struct IkeHolder {
    void* vtable;
    IkeTriple t;
};

extern "C" void fn_119_9BA4(void* result, void* a, void* b);

extern "C" IkeTriple* fn_119_9B50(IkeHolder* self, void* b) {
    IkeTriple tmp;
    fn_119_9BA4(&tmp, self, b);
    self->t.a = tmp.a;
    self->t.b = tmp.b;
    self->t.c = tmp.c;
    return &self->t;
}
