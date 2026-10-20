#pragma force_active on
struct fn_27_Obj {
    char pad[8];
    unsigned int flags;
};

extern "C" {
void fn_27_1A523C(fn_27_Obj* obj)
{
    obj->flags &= ~0x00400000;
}
}
