#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int v;
} FnObj;

extern "C" int fn_49_6D8C(FnObj *obj)
{
    unsigned int v = obj->v;
    return (int)(((v << 2) | (v >> 30)) & 0xE0000000u) >> 30;
}
