#pragma force_active on
void operator delete(void* p);

extern "C" void* fn_114_5B4C(void* p, short size) {
    if (p != 0) {
        if (size > 0) {
            operator delete(p);
        }
    }
    return p;
}
