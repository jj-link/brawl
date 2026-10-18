#pragma force_active on
typedef unsigned int u32;

typedef struct {
    char pad[8];
    u32 flags;
} FlagObj;

extern "C" int fn_77_3654(FlagObj *obj)
{
    return (obj->flags >> 25) & 1;
}
