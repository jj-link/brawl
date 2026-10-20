#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int hi : 6;
    unsigned int f : 6;
    unsigned int lo : 20;
} Obj;

void fn_48_BCF8(Obj *obj, unsigned int v)
{
    obj->f = v;
}
}
