#pragma force_active on
extern void fn_80256858(void*, int);
extern void fn_802514BC(void*, int, int);
extern unsigned char lbl_8052D5A8[];

void fn_8025443C(void* arg0, int arg1) {
    ((unsigned char*)arg0)[0x73] = arg1;
    if (arg1 == 0) {
        fn_80256858(arg0, 0);
    }
    if (lbl_8052D5A8[0x64] == 0) {
        if (arg1 == 0) {
            fn_802514BC(arg0, 0, 1);
        } else {
            fn_802514BC(arg0, 0, 0);
        }
    }
}
