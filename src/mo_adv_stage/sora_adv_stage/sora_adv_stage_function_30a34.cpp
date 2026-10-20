#pragma force_active on
struct BitfieldHolder {
    unsigned int pad[2];
    unsigned int field : 5;
};

extern "C" {
void fn_40_30A34(BitfieldHolder* p, unsigned int v) {
    p->field = v;
}
}
