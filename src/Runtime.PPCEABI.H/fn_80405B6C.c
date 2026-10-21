#pragma force_active on
extern int gDBCommTable;

typedef int (*DBCommFn)(int, int);

int fn_80405B6C(int a, int b) {
    DBCommFn f;
    int temp_r3;

    f = *(DBCommFn *)((char *)&gDBCommTable + 0x14);
    temp_r3 = f(a, b);
    return (-temp_r3 | temp_r3) >> 0x1F;
}
