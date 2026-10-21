#pragma force_active on
typedef unsigned char u8;
extern float lbl_805A4B04;
extern float lbl_805A4B08;

void fn_803EF478(u8 *arg0, float farg0) {
    if (farg0 < lbl_805A4B08) {
        *(float *)(arg0 + 0xc4) = lbl_805A4B08;
        return;
    }
    if (farg0 > lbl_805A4B04) {
        *(float *)(arg0 + 0xc4) = lbl_805A4B04;
        return;
    }
    *(float *)(arg0 + 0xc4) = farg0;
}
