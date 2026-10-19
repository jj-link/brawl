#pragma force_active on
typedef unsigned int u32;

struct Triple {
    u32 a;
    u32 b;
    u32 c;
};

struct Holder {
    void* vtable;
    Triple t;
};

extern "C" void fn_109_9494(Triple* ret, Holder* self, void* p);

extern "C" Triple* fn_109_9440(Holder* self, void* p) {
    Triple tmp;
    fn_109_9494(&tmp, self, p);
    self->t = tmp;
    return &self->t;
}
