#pragma force_active on
typedef unsigned int u32;

struct BitfieldHolder {
    u32 pad[2];
    u32 field : 5;
};

extern "C" void fn_27_19DD34(BitfieldHolder* p, u32 v)
{
    p->field = v;
}
