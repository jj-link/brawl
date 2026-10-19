#pragma force_active on
extern "C" const float lbl_90_rodata_0;

struct StCrollState {
    unsigned int field_00;
    unsigned int field_04;
    float field_08;
    float field_0C;
    float field_10;
    float field_14;
};

extern "C" void fn_90_77D8(StCrollState* object) {
    object->field_00 = 0;
    object->field_08 = lbl_90_rodata_0;
    object->field_0C = lbl_90_rodata_0;
    object->field_10 = lbl_90_rodata_0;
    object->field_14 = lbl_90_rodata_0;
}
