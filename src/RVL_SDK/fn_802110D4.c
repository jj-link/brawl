#pragma force_active on
extern int fn_80212588(int);
extern int lbl_8059ECB8;

int fn_802110D4(void)
{
    int result = 0;

    if (lbl_8059ECB8 >= 0) {
        result = fn_80212588(lbl_8059ECB8);
        if (result == 0) {
            lbl_8059ECB8 = -1;
        }
    }

    return result;
}
