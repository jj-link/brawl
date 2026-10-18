#pragma force_active on
struct Object {
    char padding[0x14C];
    float value;
    int field;
};

extern "C" void fn_27_1CB18(Object* object, float value, int field)
{
    object->field = field;
    object->value = value;
}
