#pragma force_active on
extern void fn_80254FE8(int, int);
extern void fn_802514BC(void*, int, int);
extern unsigned char lbl_8052D5A8[];

void fn_80254374(void* arg0, int arg1) {
    if (arg1 != 0) {
        lbl_8052D5A8[0x64] = 0;
        fn_80254FE8((int)arg0, 0);
        if (((unsigned char*)arg0)[0x73] == 0) {
            fn_802514BC(arg0, 0, 1);
        }
    }
}