#pragma force_active on
typedef unsigned int u32;

struct FieldBits {
    u32 unk0;
    u32 unk4;
    u32 mode : 6;
    u32 rest : 26;
};

extern "C" void fn_27_1CFB1C(FieldBits* p, u32 v)
{
    p->mode = v;
}
