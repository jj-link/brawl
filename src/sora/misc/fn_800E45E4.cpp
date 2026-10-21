#pragma force_active on
typedef unsigned char u8;
typedef signed int s32;

extern "C" {
int sprintf(char* buf, const char* fmt, ...);
void fn_800B6C38(s32, s32, char*);
extern char lbl_8059E260[8];
extern s32 lbl_805A02D8;
}

extern "C" void fn_800E45E4(s32 arg0, u8* arg1) {
    char sp8[8];
    u8 v = arg1[3];
    sprintf(sp8, lbl_8059E260, (u8)(v + 1));
    fn_800B6C38(arg0, lbl_805A02D8, sp8);
}
