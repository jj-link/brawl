#pragma force_active on
void operator delete(void* p);

extern "C" {
void* fn_102_18628(void* p, short size) {
    if (p != 0 && size > 0) {
        operator delete(p);
    }
    return p;
}
}
