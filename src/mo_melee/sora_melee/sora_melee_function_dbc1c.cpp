#pragma force_active on
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} DBCStruct;

extern "C" s32 fn_27_DBC1C(DBCStruct *p)
{
    u32 v = (p->unk8 >> 22) & 0xF;
    return (s32)(v << 28) >> 29;
}
