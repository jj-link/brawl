#pragma force_active on
extern "C" void fn_105_DF5C(void*, void*, void*);

typedef unsigned int u32;

struct Triple {
    u32 a;
    u32 b;
    u32 c;
};

struct Holder {
    u32 pad;
    Triple value;
};

extern "C" Triple* fn_105_DF08(void* self, void* arg) {
    Triple tmp;
    fn_105_DF5C(&tmp, self, arg);
    Holder* h = (Holder*)self;
    h->value = tmp;
    return &h->value;
}
