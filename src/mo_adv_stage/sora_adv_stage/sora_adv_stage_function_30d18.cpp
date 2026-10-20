#pragma force_active on
struct Obj40 {
    unsigned int w0;
    unsigned int w1;
    unsigned int bits : 5;
    unsigned int rest : 27;
};

extern "C" {
void fn_40_30D18(Obj40* p, unsigned int v) {
    p->bits = v;
}
}
