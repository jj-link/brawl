#pragma force_active on
typedef struct {
    unsigned int p[2];
    unsigned int head : 8;
    unsigned int f : 4;
    unsigned int tail : 20;
} S;

extern "C" void fn_72_5430(S *s, int arg1) {
    s->f = arg1;
}
