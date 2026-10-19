#pragma force_active on
extern "C" const float lbl_119_rodata_1C;

struct IkeObject {
    int field_0;
    unsigned char field_4;
    unsigned char padding_5[3];
    int field_8;
    int field_C;
    int field_10;
    float field_14;
};

extern "C" void fn_119_89FC(IkeObject* object, int value, int field_8)
{
    object->field_0 = value;
    object->field_4 = 0;
    object->field_8 = field_8;
    object->field_C = -1;
    object->field_10 = 0;
    object->field_14 = lbl_119_rodata_1C;
}
