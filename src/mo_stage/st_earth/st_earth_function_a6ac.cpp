#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 20;
} FnBits;

extern "C" void fn_66_A6AC(FnBits *p, unsigned int v) {
    p->b = v;
}
