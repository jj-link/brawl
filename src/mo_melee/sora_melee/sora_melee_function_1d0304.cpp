#pragma force_active on
typedef unsigned int u32;

typedef struct FieldHolder {
    char pad[8];
    u32 hi : 7;
    u32 rest : 25;
} FieldHolder;

extern "C" void fn_27_1D0304(FieldHolder *obj, u32 value)
{
    obj->hi = value;
}
