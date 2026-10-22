#pragma force_active on
extern void closesocket(int a);
extern void fn_8035A4FC(int a);
extern void fn_8035AF74(int a);
extern void fn_8035D724(void);
extern void fn_8035E00C(void *a);
extern int fn_80373924(void *a);
extern void fn_80374BD4(void *a);

void fn_80378838(void *arg0) {
    int *p = (int *)arg0;
    if (p[0x18 / 4] == 0) {
        p[0x18 / 4] = 1;
        fn_80374BD4(arg0);
        if (fn_80373924(arg0) != 0) {
            if (p[0x1C / 4] != 0) {
                p[0x14 / 4] = 1;
            } else {
                closesocket(p[0]);
                fn_8035AF74(p[0xC / 4]);
                fn_8035A4FC(p[0x10 / 4]);
                fn_8035E00C(arg0);
                fn_8035D724();
            }
        }
    }
}
