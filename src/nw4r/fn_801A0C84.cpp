#pragma force_active on
extern "C" void fn_801F0208(int, const void*, int);
extern "C" int lbl_804A46F0[4];

extern "C" void fn_801A0C84(int arg0, int arg1, int arg2) {
    lbl_804A46F0[0] = arg0;
    lbl_804A46F0[1] = arg1;
    lbl_804A46F0[2] = arg2;
    if (arg0 != 0) {
        fn_801F0208(0x15, (const void*)arg0, 0x30);
    }
    if (lbl_804A46F0[1] != 0) {
        fn_801F0208(0x16, (const void*)lbl_804A46F0[1], 0x24);
    }
    if (lbl_804A46F0[2] != 0) {
        fn_801F0208(0x17, (const void*)lbl_804A46F0[2], 0x30);
    }
}
