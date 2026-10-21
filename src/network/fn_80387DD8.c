#pragma force_active on
typedef struct {
    int pad0;
    int pad4;
    int f08;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
} Fn80387DD8Struct;

void fn_80387DD8(Fn80387DD8Struct* p) {
    p->f18 = 0;
    p->f14 = 0;
    p->f1C = 0;
    p->f0C = 0;
    p->f08 = 0;
    p->f10 = 0;
}
