#pragma force_active on
typedef unsigned int u32;

struct DonkeyTriple {
    u32 a;
    u32 b;
    u32 c;
};

struct DonkeyObj {
    u32 vt;
    DonkeyTriple t;
};

extern "C" DonkeyTriple fn_92_9C98(void* self, void* arg);

extern "C" void* fn_92_9C44(void* self, void* arg) {
    DonkeyObj* o = (DonkeyObj*)self;
    o->t = fn_92_9C98(self, arg);
    return &o->t;
}
