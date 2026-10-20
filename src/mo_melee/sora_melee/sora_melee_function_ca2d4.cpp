#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
    unsigned int unk8;
} fn_27_CA2D4_obj;

extern "C" void fn_27_CA2D4(fn_27_CA2D4_obj *p)
{
    p->unk8 &= ~0x00010000;
}
