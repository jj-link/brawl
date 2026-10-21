#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 c : 16;
    u32 b : 4;
    u32 a : 12;
} BPReg;

void fn_801F522C(u32 arg0, u32 arg1) {
    u32 r6 = 0;
    BPReg *p = (BPReg *)&r6;
    p->a = arg1 << 2;
    p->b = 0xB;
    *(u8 *)0xCC008000 = 0x20;
    p->c = arg0;
    *(u32 *)0xCC008000 = r6;
}
