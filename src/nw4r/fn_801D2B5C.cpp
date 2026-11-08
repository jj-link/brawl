#pragma force_active on
extern "C" void fn_8015C238(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_801D2B5C(void* arg0, int arg1) {
    if (arg0) {
        void* a = (char*)arg0 + 0x10;
        if (a) {
            fn_8015C238(a, 0);
        }
        void* b = (char*)arg0 + 4;
        if (b) {
            fn_8015C238(b, 0);
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
