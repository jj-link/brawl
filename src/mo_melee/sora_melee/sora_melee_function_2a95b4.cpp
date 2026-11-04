#pragma force_active on
extern "C" {
extern float lbl_27_rodata_5D7C;
extern float lbl_27_rodata_5D5C;
extern double lbl_27_rodata_5D68;
extern unsigned char* g_GameGlobal;
unsigned int __cvt_fp2unsigned(float);
void fn_27_2A95B4(unsigned char* self);
}

void fn_27_2A95B4(unsigned char* self) {
    unsigned char* q;
    unsigned int var_r30;
    unsigned int temp_r3;
    unsigned int temp_r3_2;
    int temp_r0;
    float f;
    float g;

    if (*(int*)(self + 0x148C) < 0) {
        f = *(float*)(self + 0x64);
        *(int*)(self + 0x148C) = (int)(lbl_27_rodata_5D7C * f);
    }
    if (*(int*)(self + 0x1490) < 0) {
        f = *(float*)(self + 0x70);
        *(int*)(self + 0x1490) = (int)(lbl_27_rodata_5D7C * f);
    }
    *(int*)(self + 0x1480) = *(int*)(self + 0x148C);

    q = *(unsigned char**)(g_GameGlobal + 8);
    if (q != 0) {
        var_r30 = *(unsigned int*)(q + 0x20);
        temp_r0 = (q[9] >> 5) & 7;
        switch (temp_r0) {
        case 1:
        case 2:
            var_r30 = 0x1C20;
            break;
        }
        f = *(float*)(self + 0x6C);
        temp_r3 = __cvt_fp2unsigned(
            lbl_27_rodata_5D7C * (lbl_27_rodata_5D7C * f));
        if (var_r30 == 0 || var_r30 > temp_r3) {
            var_r30 = temp_r3;
        }
        g = *(float*)(self + 0x68);
        *(float*)(self + 0x1484) = lbl_27_rodata_5D5C;
        temp_r3_2 = __cvt_fp2unsigned((float)var_r30 * g);
        *(unsigned int*)(self + 0x1488) = temp_r3_2;
        if (temp_r3_2 <= *(unsigned int*)(self + 0x1480)) {
            *(unsigned int*)(self + 0x1488) = 0;
        }
    }
}
