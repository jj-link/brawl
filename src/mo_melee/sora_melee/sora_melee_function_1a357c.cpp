#pragma force_active on
typedef struct {
    unsigned int hi : 10;
    unsigned int lo : 22;
} Bits;

typedef struct {
    unsigned int w0;
    unsigned int w1;
    Bits w2;
} Obj;

extern "C" void fn_27_1A357C(Obj* p, unsigned int v) {
    p->w2.hi = v;
}
