#pragma force_active on
extern "C" {
void* fn_123_69E4(void* object, short deleting);
void __dl__FPv(void* p);

void* fn_123_6988(void* p, short deleting) {
    if (p != 0) {
        fn_123_69E4(p, 0);
        if (deleting > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
