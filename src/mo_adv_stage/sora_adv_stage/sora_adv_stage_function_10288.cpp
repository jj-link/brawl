#pragma force_active on
struct Obj {
    char pad[0x10];
    unsigned char flag;
    float value;
};

extern const float lbl_40_rodata_14C;

extern "C" {
void fn_40_10288(Obj* p) {
    p->flag = 1;
    p->value = lbl_40_rodata_14C;
}
}
