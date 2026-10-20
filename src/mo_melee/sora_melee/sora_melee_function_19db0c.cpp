#pragma force_active on
typedef struct {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int a : 5;
    unsigned int f : 5;
    unsigned int b : 22;
} Fn2719DB0CObj;

extern "C" {
void fn_27_19DB0C(Fn2719DB0CObj* p, unsigned int v) {
    p->f = v;
}
}
