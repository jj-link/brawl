#pragma force_active on
struct Fn14CF8Object {
    char pad[8];
    float first;
    float second;
};

extern "C" {
extern const float lbl_98_rodata_A0;
}

extern "C" void fn_98_14CF8(Fn14CF8Object* obj) {
    obj->second = lbl_98_rodata_A0;
    obj->first = lbl_98_rodata_A0;
}
