#pragma force_active on
typedef struct {
    char pad[8];
    unsigned int :2;
    unsigned int f:2;
    unsigned int :28;
} FnObj;

extern "C" void fn_68_64AC(FnObj *obj, unsigned int v)
{
    obj->f = v;
}
