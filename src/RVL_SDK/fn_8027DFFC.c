#pragma force_active on
extern int fn_8027DD78(int, int);
extern unsigned int fn_8027DDE0(int, int);
extern int fn_8027DF20(void);

int fn_8027DFFC(int arg0, int arg1, int *arg2) {
    int temp_r3;

    temp_r3 = fn_8027DF20();
    if ((signed char)(fn_8027DDE0(arg0, temp_r3) >> 24) != 0) {
        *arg2 = fn_8027DD78(arg0, temp_r3);
        return 0;
    }
    return 1;
}
