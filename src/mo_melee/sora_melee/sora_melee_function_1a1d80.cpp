#pragma force_active on
typedef struct Fn27Obj {
    char pad[8];
    unsigned int value;
} Fn27Obj;

extern "C" int fn_27_1A1D80(Fn27Obj *obj)
{
    unsigned int t = ((obj->value << 6) | (obj->value >> 26)) & 0xFE000000;
    return (int)t >> 26;
}
