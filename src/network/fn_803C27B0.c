#pragma force_active on
extern unsigned int fn_803C2498(void*, unsigned int*);
extern void fn_803A9938(unsigned int, short*, short*);

short fn_803C27B0(void* arg0) {
    unsigned int spC;
    short spA;
    short sp8;

    unsigned int result = fn_803C2498(arg0, &spC);
    fn_803A9938(result, &spA, &sp8);
    return sp8;
}
