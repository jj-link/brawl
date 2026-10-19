#pragma force_active on
struct State {
    char pad[0x52C];
    int step;
};

struct Obj {
    char pad[0x0C];
    State* state;
    char pad2[0x0C];
    unsigned char flag;
    char pad3[3];
    float value;
};

extern const float lbl_40_rodata_14C;

extern "C" void fn_40_F4B4(Obj* p) {
    if (p->state->step == 2)
        return;
    if (p->flag != 0)
        return;
    p->flag = 1;
    p->value = lbl_40_rodata_14C;
}
