#pragma force_active on
typedef struct {
    char pad0[0x18];
    int f18;
    char pad1[0x15A4 - 0x1C];
    int f15A4;
    char pad2[0x15D8 - 0x15A8];
    int f15D8;
    char pad3[0x160C - 0x15DC];
    int f160C;
    char pad4[0x1648 - 0x1610];
    unsigned int f1648;
} S;

void fn_8026D4DC(S *p) {
    p->f1648 = (((p->f1648 + 7) >> 3) + 2) << 3;
    p->f18++;
    p->f15A4 = 0;
    p->f15D8 = 0;
    p->f160C = 0;
}
