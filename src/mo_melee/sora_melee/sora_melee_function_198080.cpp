#pragma force_active on
struct BitfieldHolder {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int top : 3;
    unsigned int rest : 29;
};

extern "C" void fn_27_198080(BitfieldHolder* p, unsigned int v) {
    p->top = v;
}
