#pragma force_active on
extern char lbl_80489450[];
extern char *strchr(const char *s, int c);
extern int snprintf(char *s, unsigned long n, const char *fmt, ...);
extern unsigned long strlen(const char *s);

void fn_80336344(int arg0, int arg1, const char *arg2, signed char arg3) {
    char *temp = strchr(arg2, 0);
    snprintf(temp, 0x1000, lbl_80489450, arg3, arg0, arg3, arg1);
    strlen(temp);
    strlen(arg2);
}
