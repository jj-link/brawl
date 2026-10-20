#pragma force_active on
struct FnObj71 {
    int pad0;
    int pad1;
    unsigned int flags;
};

extern "C" {
void fn_71_9F9C(FnObj71 *obj)
{
    obj->flags |= 0x02000000;
}
}
