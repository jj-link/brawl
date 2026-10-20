#pragma force_active on
struct fn_27_1A5804_S {
    unsigned int pad[2];
    unsigned int f : 4;
    unsigned int rest : 28;
};

extern "C" {
void fn_27_1A5804(fn_27_1A5804_S* p, unsigned int v) {
    p->f = v;
}
}
