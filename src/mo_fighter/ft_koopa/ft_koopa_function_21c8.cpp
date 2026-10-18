#pragma force_active on
extern "C" void* fn_102_21C8(void* p, short flag) {
    if (p && flag > 0) {
        operator delete(p);
    }
    return p;
}
