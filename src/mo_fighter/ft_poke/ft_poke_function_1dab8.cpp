#pragma force_active on
void operator delete(void*);

extern "C" void* fn_116_1DAB8(void* p, short flag) {
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}
