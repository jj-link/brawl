#pragma force_active on
extern unsigned int __peReg;

void fn_801F0B14(unsigned int arg0, unsigned int arg1) {
    unsigned short *reg = (unsigned short *)__peReg;
    reg[3] = (unsigned short)__rlwimi(arg1, arg0, 8, 0, 23);
}
