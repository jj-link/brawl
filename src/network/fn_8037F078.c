#pragma force_active on
extern void fn_8035E00C(void *);
extern void fn_80362DD4(void *);

void fn_8037F078(int *arg0) {
    int r0;

    r0 = arg0[0];
    if (r0 != 3) {
        fn_8035E00C((void *)arg0[1]);
    }
    r0 = arg0[0];
    if (r0 == 0) {
        fn_8035E00C((void *)arg0[2]);
    } else if (r0 == 1) {
        fn_8035E00C((void *)arg0[2]);
        fn_8035E00C((void *)arg0[3]);
        fn_8035E00C((void *)arg0[4]);
    } else if (r0 == 2) {
        fn_8035E00C((void *)arg0[4]);
        fn_8035E00C((void *)arg0[5]);
    } else if (r0 == 3) {
        fn_80362DD4((void *)arg0[2]);
    }
}
