#pragma force_active on
extern "C" void* fn_122_5AD4(void* p, short flag) {
    if (p && flag > 0) {
        operator delete(p);
    }
    return p;
}
