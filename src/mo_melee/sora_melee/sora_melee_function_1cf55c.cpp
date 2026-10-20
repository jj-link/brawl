#pragma force_active on
typedef unsigned int u32;

struct FlagsWord {
    u32 top : 3;
    u32 rest : 29;
};

extern "C" void fn_27_1CF55C(void* p, u32 v) {
    FlagsWord* w = (FlagsWord*)((char*)p + 8);
    w->top = v;
}
