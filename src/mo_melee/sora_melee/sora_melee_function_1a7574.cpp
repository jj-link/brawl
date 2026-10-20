#pragma force_active on
typedef struct {
    char pad[8];
    unsigned int hi : 6;
    unsigned int f : 3;
    unsigned int lo : 23;
} FnObj;

extern "C" void fn_27_1A7574(FnObj *obj, unsigned int v)
{
    obj->f = v;
}
