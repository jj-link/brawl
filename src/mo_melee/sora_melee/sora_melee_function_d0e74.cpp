#pragma force_active on
struct Object {
    unsigned char pad[8];
    unsigned int field;
};

extern "C" int fn_27_D0E74(Object* object)
{
    return (int)((object->field << 7) & 0xFF000000u) >> 25;
}
