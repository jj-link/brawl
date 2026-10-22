#pragma force_active on
extern char lbl_80529994[];
extern const unsigned char lbl_805A3AA0[8];
int fn_8024ADB0(const void *arg0, unsigned short arg1);
int fn_8024ACE8(int arg0, unsigned short arg1, int arg2);

void fn_80234A0C(char *arg0) {
    unsigned short val;
    int big;

    val = *(unsigned short *)(arg0 + 0x6);
    lbl_80529994[0x101] = (char)val;
    if ((unsigned char)val != 0) {
        big = 0x10000;
        fn_8024ADB0(lbl_805A3AA0, big - 1);
        fn_8024ACE8(0, big - 1, 1);
        return;
    }
    fn_8024ADB0(lbl_805A3AA0, 2);
    fn_8024ACE8(0, 2, 1);
}
