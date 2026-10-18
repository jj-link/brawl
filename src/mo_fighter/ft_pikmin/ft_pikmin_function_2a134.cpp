#pragma force_active on
extern "C" void fn_113_2A4AC(void*, void*);
extern "C" void* fn_113_1CFE4(void*, int);
extern "C" void fn_27_BEB00(void*);

extern "C" void fn_113_2A134(void* object, void* arg) {
    fn_113_2A4AC(arg, (char*)object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_1CFE4((char*)object + 8, i));
}
