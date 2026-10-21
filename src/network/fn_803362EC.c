#pragma force_active on
extern int snprintf(char *s, unsigned long n, const char *format, ...);
extern unsigned long strlen(const char *s);
extern char lbl_80489450[];

int fn_803362EC(int arg0, int arg1, char *arg2, signed char arg3) {
    snprintf(arg2, 0x1000, lbl_80489450, arg3, arg0, arg3, arg1);
    return strlen(arg2);
}
