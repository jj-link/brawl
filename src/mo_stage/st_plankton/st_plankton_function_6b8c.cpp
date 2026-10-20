#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int a : 4;
    unsigned int f : 4;
    unsigned int rest : 24;
} S;

extern "C" void fn_74_6B8C(S *p, unsigned int v) {
    p->f = v;
}
