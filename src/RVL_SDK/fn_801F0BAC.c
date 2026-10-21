#pragma force_active on

typedef struct {
    unsigned short x;
    unsigned short a : 12;
    unsigned short b : 1;
    unsigned short c : 3;
} PeReg;

extern PeReg *__peReg;

void fn_801F0BAC(unsigned int arg0) {
    __peReg->b = arg0;
}
