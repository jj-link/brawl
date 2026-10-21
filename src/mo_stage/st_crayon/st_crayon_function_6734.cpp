#pragma force_active on
typedef struct Obj
{
    int unk0;
    int unk4;
    unsigned int unk8;
} Obj;

extern "C" int fn_56_6734(Obj *p)
{
    return (int)((p->unk8 << 8) & 0xF8000000U) >> 28;
}
