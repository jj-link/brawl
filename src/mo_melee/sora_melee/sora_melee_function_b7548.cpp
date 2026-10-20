#pragma force_active on
extern const float lbl_27_rodata_E28;

extern "C" double atan2(double y, double x);

struct Fn27Obj {
    char pad[0x24];
    float unk24;
    float unk28;
    unsigned char pad2C;
    unsigned char unk2D;
};

extern "C" void fn_27_B7548(Fn27Obj* obj, const float* v) {
    float x = v[0];
    float y = v[1];
    float angle = (float)atan2(y, x);
    obj->unk2D = 1;
    obj->unk28 = angle;
    obj->unk24 = lbl_27_rodata_E28;
}
