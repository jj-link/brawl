#pragma force_active on
struct Object
{
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" void fn_51_DA44(Object *object)
{
    object->flags |= 0x00400000;
}
