#pragma force_active on
extern void fn_80242908(void*);

typedef struct {
    unsigned char pad0[2];
    short f2;
    short f4;
    unsigned char pad6[2];
    unsigned char f8;
    unsigned char f9;
    unsigned char fA;
    unsigned char fB;
} S;

void fn_80246414(S* p, signed char arg1) {
    p->f2 = 4;
    p->f4 = 0;
    p->f8 = 0x1A;
    p->f9 = 0xC;
    p->fA = 1;
    p->fB = arg1;
    fn_80242908(p);
}
