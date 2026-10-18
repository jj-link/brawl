#pragma force_active on
void operator delete(void* p);

extern "C" void* fn_102_1A7BC(void* p, short flag) {
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}
