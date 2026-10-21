#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int reserved : 5;
    unsigned int field : 5;
    unsigned int remaining : 22;
};

extern "C" void fn_27_19EEF8(Object* object, unsigned int value)
{
    object->field = value;
}
