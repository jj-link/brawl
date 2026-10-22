#pragma force_active on
typedef unsigned char u8;

extern int fn_80210118(void *a, void *b, int c);
extern int strcmp(const char *a, const char *b);
extern u8 lbl_8047C4E0[];
extern char lbl_8059EC88;

int fn_80210284(void) {
    char buf[4];
    u8 c;
    u8 *p;

    p = lbl_8047C4E0;
    if (fn_80210118(&lbl_8059EC88, buf, 4) != 0) {
        for (; (signed char)(c = *p) != -1; p += 5) {
            if (strcmp((char *)p + 1, buf) == 0) {
                return c;
            }
        }
    }
    return -1;
}
