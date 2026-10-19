#pragma force_active on
extern "C" int fn_27_21CBAC(void*, int);
extern "C" void fn_27_25F064(void*, int);

extern "C" void fn_27_25ECCC(void* arg) {
    int result = fn_27_21CBAC(arg, 0);
    fn_27_25F064(arg, result);
}
