#pragma force_active on
extern "C" {

void __dl__FPv(void*);

void* fn_92_12840(void* arg0, short arg1) {
    if (arg0 != 0 && arg1 > 0) {
        __dl__FPv(arg0);
    }
    return arg0;
}

}
