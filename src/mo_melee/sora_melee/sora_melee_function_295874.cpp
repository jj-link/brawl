#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int upper : 5;
    unsigned int field : 5;
    unsigned int lower : 22;
};

extern "C" void fn_27_295874(Object* object, unsigned int value)
{
    object->field = value;
}
