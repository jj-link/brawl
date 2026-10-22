#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern u16 lbl_8059FCDC;
extern s32 lbl_805A1170;
extern void *DVDGetCurrentDiskID(void);
extern u8 fn_801D6620(void);
extern s32 fn_8020D38C(s32);
extern s32 fn_8020B5A0(s32, void *);

u16 fn_80399B14(void) {
    u16 var_r31;
    u8 buf[8];
    s32 temp_r30;
    u8 temp_r3;

    var_r31 = lbl_8059FCDC;
    temp_r3 = fn_801D6620();
    switch (temp_r3) {
    case 0x40:
        var_r31 = 1;
        break;
    case 0x80:
        var_r31 = ((u16 *)DVDGetCurrentDiskID())[2];
        break;
    case 0x81:
        temp_r30 = lbl_805A1170 + 0x800;
        if (fn_8020D38C(temp_r30) == 0) {
            if (fn_8020B5A0(temp_r30, buf) == 0) {
                var_r31 = *(u16 *)(buf + 4);
            }
        }
        break;
    }
    return var_r31;
}
