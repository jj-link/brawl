#pragma force_active on
typedef struct Obj {
    int unk0;
    int unk4;
    unsigned int unk8;
} Obj;

extern "C" {
void fn_27_1A4B20(Obj *p)
{
    p->unk8 &= ~0x400u;
}
}
