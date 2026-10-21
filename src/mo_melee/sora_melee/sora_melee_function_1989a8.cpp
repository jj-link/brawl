#pragma force_active on
struct Object {
    unsigned int reserved[2];
    unsigned int flags;
};

extern "C" void fn_27_1989A8(Object* object)
{
    object->flags &= ~0x00400000u;
}
