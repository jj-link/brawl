#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_8015C538(void* arg0, int arg1);
}

void* fn_8015C538(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        __dl__FPv(arg0);
    }
    return arg0;
}
