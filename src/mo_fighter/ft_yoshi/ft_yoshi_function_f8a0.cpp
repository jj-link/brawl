#pragma force_active on
void operator delete(void* p);

extern "C" void* fn_95_F8A0(void* p, short flags) {
    if (p != 0 && flags > 0) {
        operator delete(p);
    }
    return p;
}
