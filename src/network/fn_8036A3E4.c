#pragma force_active on
extern int send(int, const void *, int, int);
extern int fn_8035C658(int);
extern void fn_80373290(void *, int, const char *);
extern void fn_8036AAF0(void *, int, int);
extern char lbl_8048ED90[];

int fn_8036A3E4(void *arg0, int arg1, const void *arg2, int arg3,
                int *arg4, int *arg5, const unsigned char *arg6)
{
    int result = send(arg1, arg2, arg3, 0);

    if (result == -1) {
        int error = fn_8035C658(arg1);

        if (error != -6 && error != -26 && error != -76) {
            if ((int)arg6[0] == 0x50 && (int)arg6[1] == 0x52) {
                return 3;
            }
            fn_80373290(arg0, 5, lbl_8048ED90);
            fn_8036AAF0(arg0, 3, 0);
            return 3;
        }
        *arg5 = 0;
        *arg4 = 0;
    } else if (result == 0) {
        *arg5 = 0;
        *arg4 = 1;
    } else {
        *arg5 = result;
        *arg4 = 0;
    }
    return 0;
}
