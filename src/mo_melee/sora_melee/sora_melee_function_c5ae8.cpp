#pragma force_active on
typedef struct {
    unsigned int w0;
    unsigned int w1;
    struct {
        unsigned int a : 2;
        unsigned int f : 2;
        unsigned int rest : 28;
    } w2;
} FnObj;

extern "C" void fn_27_C5AE8(FnObj *obj, unsigned int v)
{
    obj->w2.f = v;
}
