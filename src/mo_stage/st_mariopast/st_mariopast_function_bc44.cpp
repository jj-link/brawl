#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 6;
    unsigned int x : 6;
    unsigned int lo : 20;
} Obj;

extern "C" void fn_48_BC44(Obj *obj, unsigned int v)
{
    obj->x = v;
}
