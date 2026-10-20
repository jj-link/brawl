#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 7;
    u32 f : 7;
    u32 lo : 18;
};

extern "C" void fn_27_CFCFC(char* p, u32 v) {
    Bits* w = (Bits*)(p + 8);
    w->f = v;
}
