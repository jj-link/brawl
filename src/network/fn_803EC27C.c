#pragma force_active on

extern void OSReport(const char* msg, ...);
extern void* fn_801E0714(void);
extern char lbl_804930A0[];
extern char lbl_804930D0[];

int fn_803EC27C(int* arg0) {
    void* temp;

    if (arg0 == 0) {
        OSReport(lbl_804930A0);
        return -2;
    }
    temp = fn_801E0714();
    if (temp == 0) {
        OSReport(lbl_804930D0);
        *arg0 = 0;
        return -3;
    }
    *arg0 = (int)temp;
    return 0;
}
