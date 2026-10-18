#pragma force_active on
extern "C" void operator delete(void* p);

extern "C" void* fn_94_4750(void* p, short flags) {
    if (p != 0 && flags > 0) {
        operator delete(p);
    }
    return p;
}
