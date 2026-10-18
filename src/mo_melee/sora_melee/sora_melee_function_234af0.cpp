#pragma force_active on
extern "C" {
extern unsigned int lbl_27_data_4BE88[];

void fn_27_234AF0(unsigned int* r3, unsigned int r4, unsigned char r5) {
    r3[0] = 0;
    r3[1] = (unsigned int)lbl_27_data_4BE88;
    r3[2] = r4;
    *(unsigned char*)(r3 + 3) = r5;
}
}
