#pragma force_active on
struct FieldHolder {
    unsigned int w0;
    unsigned int w1;
    unsigned int pad0 : 4;
    unsigned int field : 2;
    unsigned int rest : 26;
};

extern "C" void fn_63_10B74(FieldHolder *p, unsigned int v) {
    p->field = v;
}
