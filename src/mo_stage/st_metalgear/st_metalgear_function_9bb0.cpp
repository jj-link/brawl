#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_71_9BB0(void* p, int flags) {
    if (p != 0 && flags > 0) {
        __dl__FPv(p);
    }
    return p;
}
