#pragma force_active on
extern void fn_802514BC(void *arg0, int arg1, int arg2);
extern void fn_8025506C(void *arg0, int arg1);
extern unsigned char lbl_8052D5A8[];

void fn_802543D8(void *arg0, int arg1) {
    if (arg1 != 0) {
        lbl_8052D5A8[0x64] = 1;
        if (((unsigned char *)arg0)[0x73] == 0) {
            fn_802514BC(arg0, 0, 0);
        }
        fn_8025506C(arg0, 0);
    }
}
