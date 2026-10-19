#pragma force_active on
typedef struct Obj
{
    int unk0;
    int unk4;
    unsigned int unk8;
} Obj;

extern "C" int fn_56_5974(Obj *p)
{
    return (int)((p->unk8 << 2) & 0xE0000000) >> 30;
}
