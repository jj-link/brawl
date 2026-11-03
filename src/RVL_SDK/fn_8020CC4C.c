#pragma force_active on
#pragma global_optimizer off

extern char *strcpy(char *, const char *);
extern unsigned long strlen(const char *);
extern void fn_8020C90C(char *, const char *, const char *);

extern char lbl_8047C120[];
extern char lbl_8059EB50;

void fn_8020CC4C(char *arg0, const char *arg1)
{
    int var_r0;
    unsigned long len;

    if (strlen(arg1) == 0) {
        strcpy(arg0, &lbl_8059EB50);
        return;
    }
    if ((int) *arg1 == 0x2F) {
        var_r0 = 0;
    } else {
        var_r0 = 1;
    }
    if (var_r0 != 0) {
        fn_8020C90C(arg0, lbl_8047C120, arg1);
        return;
    }
    strcpy(arg0, arg1);
    len = strlen(arg0);
    if (len != 0) {
        if (arg0[len - 1] == '/' && len - 1 != 0) {
            arg0[len - 1] = '\0';
        }
    }
}
