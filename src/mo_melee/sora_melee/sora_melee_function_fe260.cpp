#pragma force_active on
struct fn_27_Obj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
};

extern "C" {
void fn_27_FE260(fn_27_Obj *p)
{
    p->unk8 |= 0x2000;
}
}
