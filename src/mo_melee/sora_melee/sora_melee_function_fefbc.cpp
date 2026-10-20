#pragma force_active on
typedef unsigned int u32;

typedef struct FefbcObj {
    u32 unk0;
    u32 unk4;
    u32 pad0 : 4;
    u32 field : 2;
    u32 rest : 26;
} FefbcObj;

extern "C" void fn_27_FEFBC(FefbcObj *obj, u32 val)
{
    obj->field = val;
}
