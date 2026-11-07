#pragma force_active on
extern unsigned int fn_8035D728(void);
extern void fn_8037AC14(void *, int);
extern void *lbl_8059F9A8;

void fn_80379148(void *arg0)
{
    char *var_r31;

    var_r31 = (char *)arg0;
    if (arg0 == 0) {
        var_r31 = (char *)lbl_8059F9A8;
    }
    if (*(int *)(var_r31 + 0xBC) != 0) {
        if ((unsigned int)(fn_8035D728() - *(unsigned int *)(var_r31 + 0xAC)) < 0x2710) {
            *(int *)(var_r31 + 0xB4) = 1;
            return;
        }
        fn_8037AC14(var_r31, 1);
        *(int *)(var_r31 + 0xB4) = 0;
    }
}
