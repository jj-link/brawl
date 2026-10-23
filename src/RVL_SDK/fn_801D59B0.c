#pragma force_active on
extern unsigned char lbl_804DD140[];

void fn_801D59B0(int* unused, int* arg2) {
    switch (arg2[3]) {
    case 0:
        *(unsigned short*)0x800030E6 = *(unsigned short*)&lbl_804DD140[2] | 0x8000;
        return;
    default:
        *(unsigned short*)0x800030E6 = 1;
        return;
    }
}
