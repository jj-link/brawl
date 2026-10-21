#pragma force_active on
struct Object {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags : 3;
    unsigned int unused : 29;
};

extern "C" void fn_27_1A40A8(Object* object, unsigned int value)
{
    object->flags = value;
}
