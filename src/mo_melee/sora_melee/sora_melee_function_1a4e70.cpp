#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_35248[];

void fn_27_1A4E70(unsigned int *p) {
    unsigned int x = p[2];
    p[0] = (unsigned int)lbl_27_data_35248;
    p[1] = (unsigned int)(lbl_27_data_35248 + 0x48);
    p[2] = x & 0x01FFFFFF;
}
}
