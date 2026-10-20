#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi:4;
    unsigned int f:4;
    unsigned int lo:24;
} S;

extern "C" void fn_27_198318(S* p, unsigned int v) {
    p->f = v;
}
