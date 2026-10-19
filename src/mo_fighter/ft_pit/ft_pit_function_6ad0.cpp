#pragma force_active on
extern "C" {
void fn_27_1540CC(void*, short);
void __dl__FPv(void*);

void* fn_112_6AD0(void* obj, short flags) {
    if (obj != 0) {
        fn_27_1540CC(obj, -1);
        if (flags > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
}
