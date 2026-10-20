#pragma force_active on
extern "C" {
typedef struct Obj {
    int pad0;
    unsigned int pad1;
    unsigned int flags;
} Obj;

void fn_71_9EE4(Obj *obj)
{
    obj->flags &= 0xFDFFFFFF;
}
}
