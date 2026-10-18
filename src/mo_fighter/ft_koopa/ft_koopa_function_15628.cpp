#pragma force_active on
extern "C" {
void __dl__FPv(void*);

void* fn_102_15628(void* p, short flags) {
    if (p != 0 && flags > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
