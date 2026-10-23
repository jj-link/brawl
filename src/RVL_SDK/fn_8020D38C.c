#pragma force_active on
#pragma global_optimizer off

extern char *strcpy(char *dst, const char *src);
extern char lbl_804ED040[0x40];
extern int lbl_805A0BA8;

int fn_8020D38C(char *dst)
{
    int ready;

    if (lbl_805A0BA8 == 2) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready == 0) {
        return -0x80;
    }

    strcpy(dst, lbl_804ED040);
    return 0;
}
