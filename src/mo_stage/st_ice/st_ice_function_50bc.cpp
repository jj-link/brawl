#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_62_50BC(void* p, int flags) {
    if (p != 0) {
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
