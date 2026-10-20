#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int field : 6;
} Obj;

extern "C" void fn_48_BE68(Obj *obj, unsigned int v)
{
    obj->field = v;
}
