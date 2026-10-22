#pragma force_active on
extern "C" {
int fn_80202614(void*);
int fn_80202620(void*);
void fn_801BBC1C(void*, int*, int*);
void fn_801BBC68(void*, int, int);
extern int lbl_805A0574;
}

extern "C" int fn_801C04A4(char* self) {
    int spC;
    int sp8;
    int r31;
    unsigned int size;
    unsigned int avail;
    char* p;

    size = (fn_80202614(self + 0x30) + 0x87) & ~0x1F;
    p = *(char**)(self + 0x10);
    if (p == 0) {
        avail = 0;
    } else {
        avail = *(unsigned int*)(p + 0x1C) - (unsigned int)p;
    }
    if (size > avail) {
        return 0;
    }
    fn_801BBC1C(self + 0xC, &spC, &sp8);
    lbl_805A0574 = 0;
    r31 = fn_80202620(self + 0x30);
    fn_801BBC68(self + 0xC, spC, sp8);
    fn_80202614(self + 0x30);
    *(self + 0xC) = 1;
    return (unsigned int)(-r31 | r31) >> 31;
}
