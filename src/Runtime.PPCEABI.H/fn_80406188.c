#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_8025F9E4(void);
extern void fn_80406420(void*, void*, u32);
extern u8 lbl_8059C3E8[];
extern u8 lbl_8059BEE8[];

int gdev_cc_initialize(void) {
    fn_8025F9E4();
    fn_80406420(lbl_8059C3E8, lbl_8059BEE8, 0x500);
    return 0;
}
