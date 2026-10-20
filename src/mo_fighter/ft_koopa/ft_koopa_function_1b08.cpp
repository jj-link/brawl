#pragma force_active on
extern "C" {
void fn_102_1AA4(void*, short);
void __dl__FPv(void*);

void* fn_102_1B08(void* p, short flag) {
    if (p != 0) {
        fn_102_1AA4(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
