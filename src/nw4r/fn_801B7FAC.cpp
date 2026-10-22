#pragma force_active on
extern "C" int fn_801D2AD0(void);
extern "C" void fn_801D31E8(int, int);
extern "C" void fn_802009C8(int);

extern "C" void fn_801B7FAC(int* arg0, int arg1) {
    *arg0 = arg1;
    switch (arg1) {
    case 0:
        fn_802009C8(0);
        break;
    case 1:
        fn_802009C8(1);
        break;
    case 2:
        fn_802009C8(2);
        break;
    case 3:
        fn_802009C8(0);
        break;
    }
    int r = fn_801D2AD0();
    fn_801D31E8(r, 0x10);
}
