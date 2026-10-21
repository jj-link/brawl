#pragma force_active on
extern int closesocket(int s);

void fn_80387DF8(int *arg0) {
    closesocket(arg0[8]);
    arg0[8] = -1;
    arg0[6] = 0;
    arg0[5] = 0;
    arg0[7] = 0;
    arg0[3] = 0;
    arg0[2] = 0;
    arg0[4] = 0;
}
