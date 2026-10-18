#pragma force_active on
void operator delete(void* p);

extern "C" void* fn_110_4804(void* p, short size) {
    if (p != 0 && size > 0) {
        operator delete(p);
    }
    return p;
}
