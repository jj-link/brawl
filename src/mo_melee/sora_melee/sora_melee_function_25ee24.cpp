#pragma force_active on
extern "C" int fn_27_21CBAC(void*);
extern "C" void fn_27_25F064(void*, int);

extern "C" void fn_27_25EE24(void* arg) {
    int result = fn_27_21CBAC(arg);
    fn_27_25F064(arg, result);
}
