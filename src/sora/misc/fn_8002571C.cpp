#pragma force_active on
extern "C" {
extern int lbl_805A0020;
extern int *lbl_805A001C;
extern char lbl_80494DE0[];
void fn_8001AA88(char* a, int* b);
void fn_801F2C58(int* a, int b, int c);

void fn_8002571C(int* arg0) {
    int sp8;
    int temp_r0;

    temp_r0 = *arg0;
    lbl_805A0020 = temp_r0;
    if (temp_r0 != 0) {
        sp8 = temp_r0;
        lbl_805A001C = (int*)lbl_80494DE0;
        fn_8001AA88(lbl_80494DE0, &sp8);
        fn_801F2C58(lbl_805A001C, 1, 1);
    } else {
        lbl_805A001C = 0;
    }
}
}
