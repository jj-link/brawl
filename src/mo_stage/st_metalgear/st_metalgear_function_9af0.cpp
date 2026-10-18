#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* fn_71_9AF0(void* p, int flags);
}

void* fn_71_9AF0(void* p, int flags) {
    if (p != 0) {
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
