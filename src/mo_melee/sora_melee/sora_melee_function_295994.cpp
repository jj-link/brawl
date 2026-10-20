#pragma force_active on
typedef unsigned int u32;

struct BitfieldHolder {
    u32 unk0;
    u32 unk4;
    u32 field0 : 4;
    u32 field1 : 28;
};

extern "C" void fn_27_295994(BitfieldHolder *p, u32 v)
{
    p->field0 = v;
}
