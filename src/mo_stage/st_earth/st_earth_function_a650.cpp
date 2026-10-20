#pragma force_active on
typedef struct Obj {
    int pad[2];
    unsigned int flags;
} Obj;

extern "C" {
void fn_66_A650(Obj *obj)
{
    obj->flags &= ~0x80000;
}
}
