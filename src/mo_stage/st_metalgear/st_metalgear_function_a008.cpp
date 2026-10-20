#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
} FnObj71;

extern "C" void fn_71_A008(FnObj71 *obj, unsigned int v)
{
    obj->b = v;
}
