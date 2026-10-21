#pragma force_active on
extern unsigned int __peReg;

typedef struct {
    unsigned short pad;
    unsigned short hi : 11;
    unsigned short bit : 1;
    unsigned short lo : 4;
} PeReg;

void fn_801F0B3C(unsigned char arg0) {
    PeReg *p = (PeReg *)__peReg;
    p->bit = arg0 & 1;
}
