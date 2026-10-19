#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_110_9B10(void*, void*, void*);

struct WarioTriple {
    u32 a;
    u32 b;
    u32 c;
};

struct WarioObj {
    u32 pad;
    WarioTriple v;
};

extern "C" WarioTriple* fn_110_9ABC(WarioObj* self, void* arg) {
    WarioTriple tmp;
    fn_110_9B10(&tmp, self, arg);
    self->v = tmp;
    return &self->v;
}
