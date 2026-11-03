#pragma force_active on
extern int sprintf(char *, const char *, ...);
extern void fn_8036A680(int, void *, const char *);
extern const char lbl_8048F620[];

void fn_80370274(int arg0, void *arg1, int arg2, const int *arg3)
{
    char buf[64];

    sprintf(buf, lbl_8048F620, arg2, arg3[0], arg3[1], arg3[2]);
    fn_8036A680(arg0, arg1, buf);
}
