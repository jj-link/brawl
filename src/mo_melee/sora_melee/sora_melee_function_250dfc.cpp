#pragma force_active on
extern "C" {

void fn_27_247E58(void*, int);
void __dl__FPv(void*);

void* fn_27_250DFC(void* p, int n) {
    if (p) {
        fn_27_247E58(p, 0);
        if (n > 0)
            __dl__FPv(p);
    }
    return p;
}

}
