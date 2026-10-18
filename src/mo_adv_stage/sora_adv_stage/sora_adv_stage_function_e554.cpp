#pragma force_active on
struct StageObj {
    char pad[0x14];
    unsigned char flag;
    char pad2[3];
    float value;
};

extern "C" {
extern const float lbl_40_rodata_14C;

void fn_40_E554(StageObj* obj) {
    obj->flag = 1;
    obj->value = lbl_40_rodata_14C;
}
}
