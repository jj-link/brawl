#pragma force_active on
extern "C" {
void fn_105_1C4A4(void*, void*);
void* fn_105_1C398(void*, int);
void fn_27_BEB00(void*);
}

extern "C" void fn_105_1C10C(void* object, void* arg) {
    fn_105_1C4A4(arg, (char*)object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_105_1C398((char*)object + 8, i));
}
