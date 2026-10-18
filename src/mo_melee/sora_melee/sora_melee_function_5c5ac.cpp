#pragma force_active on
extern const float lbl_27_rodata_7D8;

struct FloatHolder {
    char pad[0x10];
    float value;
};

extern "C" bool fn_27_5C5AC(FloatHolder* p) {
    return lbl_27_rodata_7D8 != p->value;
}
