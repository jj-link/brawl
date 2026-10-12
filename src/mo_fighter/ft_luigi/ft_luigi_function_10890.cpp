struct LuigiScaleResetPrefix {
    unsigned char reserved[8];
    float scale8;
    float scaleC;
};

extern "C" const float lbl_99_rodata_58;

extern "C" void fn_99_10890(LuigiScaleResetPrefix* object) {
    object->scale8 = object->scaleC = lbl_99_rodata_58;
}
