#pragma force_active on
void operator delete(void* p);

extern "C" void* fn_120_11EC4(void* p, short n) {
    if (p && n > 0) {
        operator delete(p);
    }
    return p;
}
