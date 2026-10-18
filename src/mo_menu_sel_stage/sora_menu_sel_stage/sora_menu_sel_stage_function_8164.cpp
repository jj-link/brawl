#pragma force_active on
extern "C" {
extern unsigned char lbl_80423690;

int fn_11_8164(int obj) {
    if (lbl_80423690 != 0) {
        return 5;
    }
    return *(int*)(obj + 0x40);
}
}
