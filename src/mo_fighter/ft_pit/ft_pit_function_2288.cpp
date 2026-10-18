#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_112_2288(void* p, short flag) {
    if (p != 0) {
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
