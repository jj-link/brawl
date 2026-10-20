#pragma force_active on
typedef struct Obj {
    unsigned int w0;
    unsigned int w1;
    unsigned int f : 2;
    unsigned int rest : 30;
} Obj;

extern "C" {
void fn_62_6028(Obj *p, unsigned int v) {
    p->f = v;
}
}
