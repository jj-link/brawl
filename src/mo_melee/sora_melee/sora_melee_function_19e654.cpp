#pragma force_active on
typedef unsigned int u32;

struct BitfieldHolder {
    u32 pad[2];
    u32 hi : 6;
    u32 lo : 26;
};

extern "C" void fn_27_19E654(BitfieldHolder *p, u32 v)
{
    p->hi = v;
}
