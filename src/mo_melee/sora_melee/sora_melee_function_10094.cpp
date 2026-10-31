#pragma force_active on
extern "C" void fn_27_94D0(int* obj, int arg);
extern "C" void fn_27_96D8(int* obj, int arg);

extern "C" void fn_27_10094(int* obj, int kind, int a, int b, int c) {
    if (kind != 4) {
        if (kind >= 4) {
            return;
        }
        if (kind != 1) {
            return;
        }
        fn_27_94D0((int*)obj[1], c);
        return;
    }
    fn_27_96D8((int*)obj[1], c);
}
