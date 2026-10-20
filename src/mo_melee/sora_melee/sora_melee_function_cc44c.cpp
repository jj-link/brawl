#pragma force_active on
struct fn_27_CC44C_obj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int field8 : 5;
    unsigned int rest : 27;
};

extern "C" void fn_27_CC44C(fn_27_CC44C_obj* p, unsigned int v) {
    p->field8 = v;
}
