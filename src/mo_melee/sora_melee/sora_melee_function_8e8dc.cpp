#pragma force_active on
extern "C" float randf__Fv();
extern "C" const float lbl_27_rodata_C28;
extern "C" const float lbl_27_rodata_C2C;

extern "C" int fn_27_8E8DC(float value) {
    if (value < lbl_27_rodata_C28) {
        return 0;
    }
    if (value >= lbl_27_rodata_C2C) {
        return 1;
    }
    return randf__Fv() < value;
}
