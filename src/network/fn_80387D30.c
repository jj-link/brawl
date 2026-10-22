#pragma force_active on
extern int lbl_805A1048;
void fn_8035D720(void);
int socket(int, int, int);

void fn_80387D30(int *arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    if (arg3 != 0 || lbl_805A1048 == 1) {
        fn_8035D720();
        arg0[0] = arg2;
        arg0[1] = arg1;
        arg0[16] = 0;
        arg0[17] = arg4;
        arg0[18] = arg5;
        arg0[10] = 0;
        arg0[8] = socket(2, 2, 0x11);
        arg0[6] = 0;
        arg0[5] = 0;
        arg0[7] = 0;
        arg0[3] = 0;
        arg0[2] = 0;
        arg0[4] = 0;
    }
}
