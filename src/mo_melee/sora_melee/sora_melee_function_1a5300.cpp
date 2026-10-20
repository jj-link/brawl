#pragma force_active on
typedef struct Obj {
    int unk0;
    int unk4;
    unsigned int pad : 6;
    signed int f : 6;
    unsigned int rest : 20;
} Obj;

extern "C" int fn_27_1A5300(Obj* p)
{
    return p->f;
}
