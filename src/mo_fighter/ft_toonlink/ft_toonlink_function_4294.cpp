#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_121_4294(void* p, short size) {
    if (p != 0) {
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
