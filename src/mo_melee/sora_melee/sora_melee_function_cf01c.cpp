#pragma force_active on
struct BitfieldHolder {
    int unk0;
    int unk4;
    unsigned int field : 6;
    unsigned int rest : 26;
};

extern "C" void fn_27_CF01C(BitfieldHolder* p, unsigned int v) {
    p->field = v;
}
