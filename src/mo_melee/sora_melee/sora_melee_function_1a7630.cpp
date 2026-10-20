#pragma force_active on
typedef unsigned int u32;

struct Word {
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_1A7630(void* p, u32 v)
{
    Word* w = (Word*)((char*)p + 8);
    w->hi = v;
}
