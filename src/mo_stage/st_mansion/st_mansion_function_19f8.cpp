#pragma force_active on
struct St47Obj {
    unsigned char pad[0x6c];
    unsigned char flags;
};

extern "C" {
void fn_47_19F8(St47Obj *obj)
{
    obj->flags |= 0x8;
}
}
