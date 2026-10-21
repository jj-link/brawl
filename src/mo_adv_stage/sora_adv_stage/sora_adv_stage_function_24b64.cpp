#pragma force_active on
struct Object {
    unsigned int pad[2];
    unsigned int : 2;
    unsigned int field : 2;
    unsigned int : 28;
};

extern "C" void fn_40_24B64(Object* object, unsigned int value)
{
    object->field = value;
}
