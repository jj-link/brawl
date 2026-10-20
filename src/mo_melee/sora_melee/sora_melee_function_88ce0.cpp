#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int f : 6;
    unsigned int rest : 26;
} FnStruct;

extern "C" {
void fn_27_88CE0(FnStruct *p, unsigned int v) {
    p->f = v;
}
}
