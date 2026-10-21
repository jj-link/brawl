#pragma force_active on
struct Object {
    unsigned int unknown[2];
    unsigned int flags;
};

extern "C" void fn_27_FED48(Object* object)
{
    object->flags &= ~0x2000u;
}
