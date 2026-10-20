#pragma force_active on
extern "C" void fn_71_F04(void *arg)
{
    struct Object
    {
        unsigned char pad[0x6C];
        unsigned char flags;
    };

    Object *obj = (Object *)arg;
    unsigned int flags = obj->flags;
    flags = (flags << 0) & 0xFFFFFFF7;
    obj->flags = (unsigned char)flags;
}
