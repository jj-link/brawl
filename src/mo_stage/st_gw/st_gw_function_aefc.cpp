#pragma force_active on
extern "C" {
typedef struct {
    unsigned int pad[2];
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
} FnObj63;

void fn_63_AEFC(FnObj63 *obj, unsigned int v)
{
    obj->b = v;
}
}
