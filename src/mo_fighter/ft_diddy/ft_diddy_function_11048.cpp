#pragma force_active on
extern "C" const float lbl_115_rodata_B0;

struct DiddyData {
    int field_00;
    unsigned char field_04;
    unsigned char padding_05[3];
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    float field_18;
    unsigned char field_1C;
};

extern "C" void fn_115_11048(DiddyData* object, int value0, int value1, unsigned char value2) {
    object->field_00 = value0;
    object->field_04 = 0;
    object->field_08 = value1;
    object->field_0C = -1;
    object->field_10 = -1;
    object->field_14 = -1;
    object->field_18 = lbl_115_rodata_B0;
    object->field_1C = value2;
}
