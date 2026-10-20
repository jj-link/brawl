#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
} FlagBits;

typedef struct {
    u32 unk0;
    u32 unk4;
    FlagBits flags;
} FlagsObj;

extern "C" void fn_27_CD59C(FlagsObj *obj, u32 val)
{
    obj->flags.b = val;
}
