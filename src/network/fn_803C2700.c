#pragma force_active on
extern unsigned int fn_803C22DC(unsigned int, int *);
extern void fn_803A9938(unsigned int, short *, short *);

short fn_803C2700(void) {
    unsigned int r;
    int spC;
    short spA;
    short sp8;

    r = fn_803C22DC(r, &spC);
    fn_803A9938(r, &spA, &sp8);
    return spA;
}
