#pragma force_active on
struct F {
    unsigned int p[2];
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
};

extern "C" void fn_72_52DC(F *s, unsigned int v) {
    s->b = v;
}
