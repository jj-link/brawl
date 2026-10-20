#pragma force_active on
typedef unsigned int u32;

struct Flags {
    char pad[8];
    u32 hi : 4;
    u32 f : 2;
    u32 lo : 26;
};

extern "C" void fn_27_19EC2C(void* self, u32 v) {
    Flags* s = (Flags*)self;
    s->f = v;
}
