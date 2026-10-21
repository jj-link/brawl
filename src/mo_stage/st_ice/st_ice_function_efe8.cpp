#pragma force_active on

typedef struct {
    int pad[2];
    unsigned int f : 2;
    unsigned int rest : 30;
} Obj;

extern "C" void fn_62_EFE8(Obj *p, unsigned int v) {
    p->f = v;
}
