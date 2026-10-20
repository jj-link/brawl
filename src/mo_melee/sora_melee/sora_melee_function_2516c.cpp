#pragma force_active on
extern "C" extern const float lbl_27_rodata_38C;

struct fn_27_2516C_obj {
    char pad[0x3c];
    float value;
};

extern "C" void fn_27_2516C(fn_27_2516C_obj* obj) {
    obj->value = lbl_27_rodata_38C;
}
