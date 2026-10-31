#pragma force_active on

extern int fn_8020CAD4(void);
extern int fn_8020CAEC(void);
extern int fn_80214F38(int, int *);

int fn_8020B0E4(int *arg0, int *arg1) {
    int local[8] __attribute__((aligned(32)));
    int value;

    if (fn_8020CAD4() == 0) {
        return -0x80;
    }

    if (fn_80214F38(*arg0, local) == 0) {
        if (arg1) {
            value = local[0];
            *arg1 = value;
            {
                int flag = 0;
                if (flag) {
                    *(int *)0 = 0;
                }
            }
        }
    }

    return fn_8020CAEC();
}
