#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
} FlagObj;

extern "C" {
void fn_27_1999B4(FlagObj *obj, u32 value)
{
    obj->b = value;
}
}
