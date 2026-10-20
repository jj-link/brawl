#pragma force_active on
typedef struct Obj {
    int pad[2];
    unsigned int flags;
} Obj;

extern "C" {
int fn_70_8FA0(Obj *obj)
{
    unsigned int v = obj->flags;
    int x = (int)(((v << 2) | (v >> 30)) & 0xE0000000u);
    return x >> 30;
}
}
