#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad[2];
    u32 a : 12;
    u32 f : 6;
    u32 b : 14;
};

extern "C" void fn_27_CEF08(Flags* p, u32 v) {
    p->f = v;
}
