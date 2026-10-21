#pragma force_active on
extern unsigned char lbl_8053A6E0[];

int fn_803ADD34(int arg0) {
    unsigned char idx = arg0;
    return *(int *)(lbl_8053A6E0 + idx * 0x2C + 0x710);
}
