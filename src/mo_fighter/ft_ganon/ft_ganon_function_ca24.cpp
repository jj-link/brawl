#pragma force_active on
extern "C" const float lbl_109_rodata_18;

struct Ganon109CA24 {
    int field_00;
    unsigned char field_04;
    unsigned char pad_05[3];
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    float field_18;
    unsigned char field_1C;
};

extern "C" void fn_109_CA24(Ganon109CA24* object, int value4, int value8, unsigned char value1C) {
    object->field_00 = value4;
    object->field_04 = 0;
    object->field_08 = value8;
    object->field_0C = -1;
    object->field_10 = -1;
    object->field_14 = -1;
    object->field_18 = lbl_109_rodata_18;
    object->field_1C = value1C;
}
