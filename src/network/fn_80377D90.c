#pragma force_active on
extern int *fn_8035B1C4(int, int **);

int fn_80377D90(int arg0, int arg1, short arg2) {
    struct Locals {
        int *sp8;
        char pad0[4];
        int sp10;
        short sp14;
        char pad1[0x98];
    } loc;
    int *temp;
    loc.sp10 = arg1;
    loc.sp14 = arg2;
    loc.sp8 = &loc.sp10;
    temp = fn_8035B1C4(*(int *)((char *)arg0 + 0xC), &loc.sp8);
    if (temp != 0) {
        return *temp;
    }
    return 0;
}
