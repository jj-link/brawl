#pragma force_active on
struct Entry { int a, b, c; };
extern "C" void fn_801A0C84(int, int, int);
extern "C" void fn_801D7AE4(int);
extern "C" void fn_801D50A0();
extern "C" Entry* fn_801A6378(int*, int*, int, int, int);
extern "C" int fn_801A66D8(void*, void*);
extern "C" int fn_801A6714(void*, void*);
extern "C" void fn_801A6778(Entry*, Entry*, int (*)(void*, void*));
extern "C" void fn_801A6208(int*, Entry*, int, int, int);
extern "C" void fn_801A60E8(int*, Entry*, int, int);
extern "C" void fn_801A5F1C(int*, int, int, int);
extern "C" void fn_801A5DD4(int*, int, int);
extern "C" void fn_801A64B0(int* arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    int sp34, sp30;
    fn_801A0C84(arg1, arg2, arg3);
    if (!(arg7 & 0x10)) {
        fn_801D7AE4(0);
        fn_801D50A0();
    }
    if (arg4) {
        if (arg7 & 1) {
            int sp2c = *arg0;
            Entry* p = fn_801A6378(&sp34, &sp2c, arg1, arg4, arg6);
            fn_801A6778(p, p + sp34, fn_801A66D8);
            if (arg6) {
                int sp28 = *arg0;
                fn_801A6208(&sp28, p, sp34, arg6, arg7);
            } else {
                int sp24 = *arg0;
                fn_801A60E8(&sp24, p, sp34, arg7);
            }
        } else if (arg6) {
            int sp20 = *arg0;
            fn_801A5F1C(&sp20, arg4, arg6, arg7);
        } else {
            int sp1c = *arg0;
            fn_801A5DD4(&sp1c, arg4, arg7);
        }
    }
    if (arg5) {
        if (arg7 & 2) {
            int sp18 = *arg0;
            Entry* p = fn_801A6378(&sp30, &sp18, arg1, arg5, arg6);
            fn_801A6778(p, p + sp30, fn_801A6714);
            if (arg6) {
                int sp14 = *arg0;
                fn_801A6208(&sp14, p, sp30, arg6, arg7);
            } else {
                int sp10 = *arg0;
                fn_801A60E8(&sp10, p, sp30, arg7);
            }
        } else if (arg6) {
            int spc = *arg0;
            fn_801A5F1C(&spc, arg5, arg6, arg7);
        } else {
            int sp8 = *arg0;
            fn_801A5DD4(&sp8, arg5, arg7);
        }
    }
    fn_801A0C84(0, 0, 0);
}