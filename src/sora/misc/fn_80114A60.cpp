#pragma force_active on
extern "C" unsigned int fn_80114670();
extern "C" void fn_80114868(int, int);

extern "C" void fn_80114A60(int arg0, int arg1) {
    if (fn_80114670() != 1) {
        fn_80114868(arg0, arg1);
    }
}
