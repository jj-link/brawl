#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern s32 *DVDGetCurrentDiskID(void);
extern s32 *OSGetAppGamename(void);
extern u8 fn_801D6620(void);

s32 fn_80399AC8(void) {
    s32 var_r31;

    var_r31 = *OSGetAppGamename();
    if (var_r31 == 0) {
        if (fn_801D6620() == 0) {
            var_r31 = *DVDGetCurrentDiskID();
        }
    }
    return var_r31;
}
