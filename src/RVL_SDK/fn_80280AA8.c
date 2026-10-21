#pragma force_active on
typedef signed int s32;
extern char lbl_8040F560[];
s32 fn_802819D0(char *buf, s32 size, char *fmt, ...);
void fn_80280840(s32 p, char *buf);

void *fn_80280AA8(void *arg0, s32 arg1) {
    char sp8[0x400];

    fn_802819D0(sp8, 0x400, lbl_8040F560 + 0x15, arg1);
    fn_80280840(*(s32 *)((char *)arg0 + 0x8), sp8);
    return arg0;
}
