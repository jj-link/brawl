#pragma force_active on
typedef struct {
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
} Bits;

typedef struct {
    int pad[2];
    Bits flags;
} Obj;

extern "C" void fn_27_1987E0(Obj* p, unsigned int v) {
    p->flags.b = v;
}
