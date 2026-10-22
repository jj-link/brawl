#pragma force_active on
extern int fn_8020CAD4(void);
extern int fn_8020CAEC(void);
extern int fn_80213E00(int *);

int fn_8020D7BC(int *arg0) {
    int buf[7];

    if (fn_8020CAD4() == 0) {
        return -0x80;
    }
    if (fn_80213E00(buf) == 0) {
        arg0[0] = buf[0];
        arg0[1] = buf[1];
        arg0[2] = buf[2];
        arg0[3] = buf[3];
        arg0[4] = buf[4];
        arg0[5] = buf[5];
        arg0[6] = buf[6];
    }
    return fn_8020CAEC();
}
