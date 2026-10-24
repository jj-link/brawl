#pragma force_active on

extern int fn_8020CAD4(void);
extern int fn_8020CAEC(void);
extern int fn_80214F38(int, int *);

int fn_8020B16C(int *arg0, int *arg1) {
    int buf[8] __attribute__((aligned(32)));

    if (fn_8020CAD4() == 0) {
        return -0x80;
    }

    if (fn_80214F38(*arg0, buf) == 0) {
        int flag = 0;

        if (flag) {
            *(int *)0 = 0;
        }

        if (arg1 != 0) {
            *arg1 = buf[1];
        }
    }

    return fn_8020CAEC();
}
