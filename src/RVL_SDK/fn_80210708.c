#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_801D8690(const char *, int, const char *, ...);
extern char lbl_8047C538[0x22];
extern int lbl_8059ECB0;

int fn_80210708(u8 *arg0, u32 *arg1) {
    u32 temp_r5;
    u32 temp_r6;

    temp_r5 = ((u32 *)arg0)[0];
    if (temp_r5 - 0x55AA0000 != 0x382DU) {
        fn_801D8690((const char *)&lbl_8059ECB0, 0x4A, lbl_8047C538);
    }
    arg1[0] = (u32)arg0;
    temp_r6 = (u32)arg0 + ((u32 *)arg0)[1];
    arg1[1] = temp_r6;
    arg1[2] = (u32)arg0 + ((u32 *)arg0)[3];
    temp_r5 = ((u32 *)temp_r6)[2];
    arg1[3] = temp_r5;
    arg1[4] = temp_r6 + temp_r5 * 12;
    arg1[5] = ((u32 *)arg0)[2];
    arg1[6] = 0;
    return 1;
}
