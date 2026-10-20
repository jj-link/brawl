#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 10;
    u32 f : 5;
    u32 b : 17;
};

struct Holder {
    u32 pad[2];
    Flags fl;
};

extern "C" void fn_27_19EDC4(Holder *p, u32 v) {
    p->fl.f = v;
}
