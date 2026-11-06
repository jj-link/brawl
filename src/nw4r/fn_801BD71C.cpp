#pragma force_active on
extern "C" void fn_8015C238(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_801BD71C(void* arg0, int arg1) {
    if (arg0) {
        void* sub = (char*)arg0 + 4;
        if (sub) {
            fn_8015C238(sub, 0);
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
