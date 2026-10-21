#pragma force_active on

typedef struct {
    unsigned short x;
    unsigned short a:13;
    unsigned short b:1;
    unsigned short c:2;
} PeReg;

extern PeReg *__peReg;

void fn_801F0BD8(unsigned int arg0) {
    __peReg->b = arg0;
}
