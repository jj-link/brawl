#pragma force_active on
extern "C" {
void fn_79_1AB4(void* obj, int flags);
void __dl__FPv(void* p);
void* fn_79_A7C0(void* obj, int flags);
}

void* fn_79_A7C0(void* obj, int flags) {
    if (obj != 0) {
        fn_79_1AB4(obj, 0);
        if (flags > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
