#pragma force_active on
extern "C" {
extern int gUnk805a03d8;

int fn_800CCF1C() {
    unsigned int x = (unsigned int)gUnk805a03d8 - 3;
    return (int)((unsigned int)__cntlzw(x) >> 5);
}
}
