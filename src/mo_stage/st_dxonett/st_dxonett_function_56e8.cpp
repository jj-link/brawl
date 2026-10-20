#pragma force_active on
struct Object {
    unsigned int unknown[2];
    unsigned int flags;
};

extern "C" void fn_78_56E8(Object* object)
{
    object->flags &= ~0x02000000u;
}
