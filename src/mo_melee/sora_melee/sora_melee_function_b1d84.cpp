#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 pad0;
    u32 pad4;
    u32 hi : 6;
    u32 mid : 3;
    u32 lo : 23;
};

extern "C" void fn_27_B1D84(char* self, u32 v) {
    Flags* f = *(Flags**)(self + 4);
    f->mid = v;
}
