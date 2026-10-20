#pragma force_active on
typedef struct {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int f : 4;
    unsigned int rest : 28;
} BitField;

extern "C" {
void fn_27_19F538(BitField *p, unsigned int v) {
    p->f = v;
}
}
