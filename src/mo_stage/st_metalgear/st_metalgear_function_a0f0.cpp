#pragma force_active on
struct Object
{
    unsigned int padding[2];
    unsigned int unused : 2;
    unsigned int field : 2;
    unsigned int rest : 28;
};

extern "C" void fn_71_A0F0(Object* object, unsigned int value)
{
    object->field = value;
}
