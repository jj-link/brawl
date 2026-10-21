#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int flags : 4;
    unsigned int remaining : 28;
};

extern "C" void fn_71_F748(Object* object, unsigned int value)
{
    object->flags = value;
}
