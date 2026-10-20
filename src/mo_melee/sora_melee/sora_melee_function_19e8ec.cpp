#pragma force_active on
struct fn_27_Obj {
    int unk0;
    int unk4;
    unsigned int unk8;
};

extern "C" {
void fn_27_19E8EC(fn_27_Obj* p)
{
    p->unk8 &= ~0x00010000;
}
}
