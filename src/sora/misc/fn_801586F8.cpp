#pragma force_active on
typedef struct {
    int f0;   // 0x00
    int f1;   // 0x04
    int f2;   // 0x08
    int f3;   // 0x0C
    int f4;   // 0x10
    int f5;   // 0x14
    int f6;   // 0x18
    int f7;   // 0x1C
    int f8;   // 0x20
    int f9;   // 0x24
    int f10;  // 0x28
    int f11;  // 0x2C
    int f12;  // 0x30
} FnState;

extern "C" void fn_801586F8(FnState* p) {
    p->f0 = -1;
    p->f1 = 0;
    p->f2 = -1;
    p->f3 = 0;
    p->f4 = 0;
    p->f5 = -1;
    p->f9 = 0;
    p->f6 = -1;
    p->f10 = 0;
    p->f7 = -1;
    p->f11 = 0;
    p->f8 = -1;
    p->f12 = 0;
}
