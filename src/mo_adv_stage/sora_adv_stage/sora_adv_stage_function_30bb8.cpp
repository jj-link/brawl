#pragma force_active on
struct Obj40 {
    int pad[2];
    unsigned int kind : 5;
    unsigned int rest : 27;
};

extern "C" {
void fn_40_30BB8(Obj40* p, unsigned int v) {
    p->kind = v;
}
}
