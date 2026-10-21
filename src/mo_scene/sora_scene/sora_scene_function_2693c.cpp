#pragma force_active on
typedef unsigned char u8;
typedef int s32;
extern s32 lbl_1_data_72B0;

extern "C" void fn_1_2693C(s32 arg0) {
    s32 v = arg0;
    s32 *p;
    s32 i;
    if (v >= 0x1D) {
        goto L974;
    }
    if (v >= 0xE) {
        goto L960;
    }
    if (v >= 5) {
        goto done;
    }
    if (v >= 3) {
        goto set3;
    }
    goto done;
L960:
    if (v >= 0x13) {
        goto done;
    }
    if (v >= 0x10) {
        goto set16;
    }
    goto set14;
L974:
    if (v == 0x49) {
        goto set3;
    }
    if (v >= 0x49) {
        goto L994;
    }
    if (v >= 0x48) {
        goto set1d;
    }
    if (v >= 0x23) {
        goto done;
    }
    goto set1d;
L994:
    if (v >= 0x4B) {
        goto done;
    }
    goto set14;
set16:
    v = 16;
    goto done;
set1d:
    v = 29;
    goto done;
set3:
    v = 3;
    goto done;
set14:
    v = 14;
done:
    p = &lbl_1_data_72B0;
    for (i = 0; i < 0x23; i++) {
        if (v == *p) {
            *((u8 *)&lbl_1_data_72B0 + i * 12 + 8) = 1;
            return;
        }
        p += 3;
    }
}
