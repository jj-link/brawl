#pragma force_active on
typedef unsigned int u32;

struct FlagHolder {
    u32 unk0;
    u32 unk4;
    u32 field : 10;
    u32 rest : 22;
};

extern "C" void fn_27_1A398C(FlagHolder* p, u32 v)
{
    p->field = v;
}
