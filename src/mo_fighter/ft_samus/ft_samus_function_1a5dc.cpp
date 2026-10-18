#pragma force_active on
void operator delete(void* p);

extern "C" void* fn_94_1A5DC(void* p, short flag) {
    if (p != 0 && flag > 0) {
        operator delete(p);
    }
    return p;
}
