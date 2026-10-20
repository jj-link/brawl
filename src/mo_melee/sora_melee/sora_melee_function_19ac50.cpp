#pragma force_active on
struct Object
{
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_27_19AC50(Object *object)
{
    object->flags |= 0x02000000;
}
