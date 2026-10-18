#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_105_1ABD4(void* p, short flags) {
    if (p != 0 && flags > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
