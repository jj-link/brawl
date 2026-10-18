#pragma force_active on
extern void operator delete(void* p);

extern "C" void* fn_104_E064(void* p, short flag) {
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}
