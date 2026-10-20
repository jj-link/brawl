#pragma force_active on
extern "C" {

void __dl__FPv(void*);
void fn_27_247E58(void*, int);

void* fn_27_24DFF4(void* a, int b) {
    if (a != 0) {
        fn_27_247E58(a, 0);
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}

}
