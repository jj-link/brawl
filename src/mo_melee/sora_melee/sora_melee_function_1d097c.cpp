#pragma force_active on
struct FieldHolder {
    int unk0;
    int unk4;
    unsigned int top : 4;
    unsigned int rest : 28;
};

extern "C" void fn_27_1D097C(FieldHolder* p, unsigned int v) {
    p->top = v;
}
