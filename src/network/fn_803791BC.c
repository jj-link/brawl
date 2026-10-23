#pragma force_active on
extern int closesocket(int);
extern void fn_8035D724(void);
extern void fn_8035E00C(void *);
extern void fn_8037AC14(void *, int);
extern char lbl_8048FBE0[];
extern void *lbl_8059F9A8;

void fn_803791BC(void *arg0)
{
    char *var_r31;

    var_r31 = (char *)arg0;
    if (arg0 == 0) {
        var_r31 = (char *)lbl_8059F9A8;
    }
    if (*(int *)(var_r31 + 0xBC) != 0) {
        fn_8037AC14(var_r31, 2);
    }
    if (*(int *)(var_r31 + 0x00) != -1) {
        if (*(int *)(var_r31 + 0xC4) != 0) {
            closesocket(*(int *)(var_r31 + 0x00));
        }
    }
    *(int *)(var_r31 + 0x00) = -1;
    *(int *)(var_r31 + 0xAC) = 0;
    if (*(int *)(var_r31 + 0xC4) != 0) {
        fn_8035D724();
    }
    if (var_r31 != lbl_8048FBE0) {
        fn_8035E00C(var_r31);
    }
}
