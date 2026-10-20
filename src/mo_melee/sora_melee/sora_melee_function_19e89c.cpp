#pragma force_active on
struct FnBits {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int top : 5;
    unsigned int rest : 27;
};

extern "C" void fn_27_19E89C(FnBits *p, unsigned int v) {
    p->top = v;
}
