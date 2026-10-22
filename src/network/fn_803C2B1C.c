#pragma force_active on
extern char lbl_8053B248[];

int fn_803A9BB4(void *, int, int);
int fn_803BC2C0(void *, int, int *);
int fn_803C27EC(int);
int fn_803C291C(int, int);

int fn_803C2B1C(int arg0, int arg1) {
    char sp10[0x10];
    int sp8;
    int temp_r3;
    int temp_r3_2;

    temp_r3 = fn_803C27EC(arg1);
    if (temp_r3 == 0) {
        *(int *)(lbl_8053B248 + 0x1C) = 0xA;
        return 0;
    }
    temp_r3_2 = fn_803A9BB4(sp10, arg0, 1);
    if (temp_r3_2 == 0) {
        temp_r3_2 = fn_803BC2C0(sp10, temp_r3, &sp8);
    } else {
        *(int *)(lbl_8053B248 + 0x1C) = temp_r3_2;
    }
    return fn_803C291C(temp_r3_2, sp8);
}
