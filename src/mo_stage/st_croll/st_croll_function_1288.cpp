#pragma force_active on
struct CrollObject {
    unsigned char pad_000[0x8C];
    unsigned int field_08C;
    unsigned int field_090;
    unsigned char pad_094[0x0C];
    unsigned int field_0A0;
    unsigned int field_0A4;
    float field_0A8;
    unsigned char pad_0AC[0x14];
    unsigned char field_0C0;
    unsigned char pad_0C1[0x1B];
    float field_0DC;
};

extern "C" const float lbl_90_rodata_20;
extern "C" const float lbl_90_rodata_0;

extern "C" void fn_90_1288(CrollObject* object) {
    object->field_08C = 0;
    object->field_090 = 0;
    object->field_0A0 = 0;
    object->field_0A4 = 0;
    object->field_0A8 = lbl_90_rodata_20;
    object->field_0C0 = 0;
    object->field_0DC = lbl_90_rodata_0;
}
