#pragma force_active on
extern "C" {

extern float lbl_805A16E8;
extern int *lbl_805A0098;

void fn_800381E8(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    int b = p[0x4C];
    float f = lbl_805A16E8;
    b &= 0xFFFFFFDF;
    *(int *)(p + 0x3C) = 0;
    *(float *)(p + 0x44) = f;
    p[0x4C] = (unsigned char)b;
    lbl_805A0098 = (int *)arg0;
}

}
