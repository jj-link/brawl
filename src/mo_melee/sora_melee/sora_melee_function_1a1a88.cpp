#pragma force_active on
typedef unsigned int u32;

struct Word {
    u32 hi : 6;
    u32 rest : 26;
};

extern "C" void fn_27_1A1A88(void* p, u32 v) {
    Word* w = (Word*)((char*)p + 8);
    w->hi = v;
}
