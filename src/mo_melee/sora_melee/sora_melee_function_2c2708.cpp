#pragma force_active on
typedef struct {
    int unk0;
    int unk4;
} fn_27_2C2708_Obj;

extern "C" {
unsigned int fn_27_2C2708(fn_27_2C2708_Obj *p)
{
    return (unsigned int)(p->unk4 >> 24) >> 31;
}
}
