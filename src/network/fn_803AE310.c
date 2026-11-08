#pragma force_active on
typedef struct { char pad[0x1b8]; struct { int value; char pad[0x30]; } a[25]; char pad2[0x30]; struct { int value; char pad[0x28]; } b[26]; } State;
extern State lbl_8053A6E0;
extern void *fn_803A976C(void *, int, unsigned int);
int fn_803AE310(void) {
    int i;
    fn_803A976C(&lbl_8053A6E0, 0, 0xb64);
    for (i = 0; i < 26; i++) lbl_8053A6E0.a[i].value = 0;
    for (i = 0; i < 26; i++) lbl_8053A6E0.b[i].value = 0;
    return 0;
}