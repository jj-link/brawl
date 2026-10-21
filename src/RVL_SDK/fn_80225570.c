#pragma force_active on

extern unsigned char lbl_804F9FC0[];

void fn_80225570(int idx, float a, float b) {
    unsigned char* p = lbl_804F9FC0 + idx * 0x528;
    *(float*)(p + 0x9c) = a;
    *(float*)(p + 0xa0) = b;
}
