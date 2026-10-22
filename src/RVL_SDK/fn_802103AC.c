#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;

extern int fn_80210118(void *, void *, int);
extern int strcmp(const char *, const char *);
extern u8 lbl_8047C528[];
extern char lbl_8059ECA4;

int fn_802103AC(void) {
    char buf[16];
    u8 id;
    u8 *p;

    p = lbl_8047C528;
    if (fn_80210118(&lbl_8059ECA4, buf, 3) != 0) {
        while ((s8)(id = *p) != -1) {
            if (strcmp((char *)p + 1, buf) == 0) {
                return id;
            }
            p += 4;
        }
    }
    return -1;
}
