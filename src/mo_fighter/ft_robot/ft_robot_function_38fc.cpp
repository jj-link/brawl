#pragma force_active on
extern "C" void* fn_120_38FC(void* p, short size) {
    if (p != 0 && size > 0) {
        operator delete(p);
    }
    return p;
}
