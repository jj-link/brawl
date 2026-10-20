#pragma force_active on
struct Fn51_667C_Object
{
    unsigned int reserved[2];
    unsigned int flags;
};

extern "C" void fn_51_667C(Fn51_667C_Object *object)
{
    object->flags &= ~(1u << 25);
}
